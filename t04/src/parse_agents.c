#include "../inc/parse_agents.h"

int main(int argc, char *argv[]) {
    struct s_input *input = mx_parse_input(argc, argv);
    if (!input) exit(1);
    t_agent **agents = mx_parse_agents(input->p_json);
    mx_sort_agents(agents, input->agent_count, input->f);
    agents ? print_agents(agents) : ERROR
    mx_exterminate_agents(&agents);
    free(input->p_json);
    free(input);
    exit(agents ? 0 : 1);
}

struct s_input *mx_parse_input(int argc, char *argv[]) {
    if (argc != 3 || (mx_strcmp(argv[1], NAME_FLAG) != 0
            && mx_strcmp(argv[1], STRENGTH_FLAG) != 0
            && mx_strcmp(argv[1], POWER_FLAG) != 0)) {
        USAGE
        return NULL;
    }
    char *p_json = mx_file_to_str(argv[2]);
    int count = mx_get_agent_count(p_json);
    if (count == -1) {
        if (p_json) free(p_json);
        ERROR 
        return NULL;
    }
    struct s_input *input = malloc(sizeof(struct s_input));
    input->f = mx_get_sort_by_from_flag(argv[1]);
    input->p_json = p_json;
    input->agent_count = count;
    return input;
}

int mx_get_agent_count(char *p_json) {
    if (!p_json) return -1;

    int len = mx_count_words(p_json, '\n');
    if (len <= 0 || len % 5) return -1;

    return len / 5;
}

t_agent **mx_parse_agents(char *p_json) {
    if (!p_json) return NULL;
    int len = mx_count_words(p_json, '\n');
    if (len <= 0 || len % 5) return NULL;
    char **sentences = mx_strsplit(p_json, '\n');
    if (!sentences) return NULL;
    t_agent **agents = malloc(sizeof(t_agent *) * (len / 5) + sizeof(NULL));
    if (!agents) {
        mx_del_strarr(&sentences);
        return NULL;
    }
    agents[len/5] = NULL;
    for (int i = 0, j = 0; i < len; i += 5, j++) {
        agents[j] = mx_parse_agent(sentences + i);
        if (!agents[j]) {
            mx_del_strarr(&sentences);
            mx_exterminate_agents(&agents);
            return NULL;
        }
    }
    mx_del_strarr(&sentences);
    return agents;
}

t_agent *mx_parse_agent(char **sentences) {
    if (!sentences[4] || mx_count_words(sentences[0], ' ') != 2
            || mx_count_words(sentences[4], ' ') != 1) return NULL;
    char **agent_start = mx_strsplit(sentences[0], ' ');
    if (mx_strcmp(agent_start[0], AGENT) != 0 
            || mx_strcmp(agent_start[1], "{") != 0
            || mx_strcmp(sentences[4], "}") != 0) {
        mx_del_strarr(&agent_start);
        return NULL;
    }
    mx_del_strarr(&agent_start);
    t_agent *agent = mx_create_agent("NULL", 0, 0);
    for (int i = 1; i < 4; i++) {
        if (!sentences[i] || !mx_parse_agent_arg(sentences[i], agent)) {
            free(agent->name);
            free(agent);
            return NULL;
        }
    }
    return agent;
}

bool mx_parse_agent_arg(char *sentence, t_agent *agent) {
    if (mx_count_words(sentence, ' ') != 2) return false;
    char **words = mx_strsplit(mx_skip_spaces(sentence), ' ');
    if (!words) return NULL;
    if (mx_strcmp(NAME, words[0]) == 0) {
        agent->name = mx_strdup(words[1]);
    }
    else if (mx_strcmp(POWER, words[0]) == 0 && mx_isnumber(words[1])) {
        int power = mx_atoi(words[1]);
        agent->power = power;
    }
    else if (mx_strcmp(STRENGTH, words[0]) == 0 && mx_isnumber(words[1])) {
        int strength = mx_atoi(words[1]);
        agent->strength = strength;
    }
    else {
        mx_del_strarr(&words);
        return false;
    }
    mx_del_strarr(&words);
    return true;
}
