#include "../inc/print_agents.h"

static void print_agent(t_agent *agent) {
    mx_printstr("agent: ");
    mx_printstr(agent->name);
    mx_printstr(", strength: ");
    mx_printint(agent->strength);
    mx_printstr(", power: ");
    mx_printint(agent->power);
    mx_printchar('\n');
}
void print_agents(t_agent **agents) {
    for (int i = 0; agents[i]; i++) {
        print_agent(agents[i]);
    }
}

