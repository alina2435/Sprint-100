#pragma once

#include "../inc/print_agents.h"
#include "../inc/file_to_str.h"
#include "../inc/str_utils.h"
#include "../inc/agent.h"
#include "../inc/print.h"
#include "../inc/atoi.h"

#define USAGE mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
#define ERROR mx_printerr("error\n");
#define AGENT "agent"
#define NAME "name:"
#define POWER "power:"
#define STRENGTH "strength:"

struct s_input {
    char *p_json;
    int agent_count;
    sort_by f;
};

struct s_input *mx_parse_input(int argc, char *argv[]);
t_agent **mx_parse_agents(char *p_json);
t_agent *mx_parse_agent(char **sentences);
int mx_get_agent_count(char *p_json);
bool mx_parse_agent_arg(char *sentence, t_agent *agent);
