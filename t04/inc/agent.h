#pragma once

#include "str_utils.h"

#define NAME_FLAG "-n"
#define POWER_FLAG "-p"
#define STRENGTH_FLAG "-s"

typedef struct s_agent {
    char *name;
    int power;
    int strength;
} t_agent;

typedef bool (*sort_by)(t_agent*, t_agent*);

t_agent *mx_create_agent(char *name, int power, int strength);
void mx_exterminate_agents(t_agent ***agents);
void mx_sort_agents(t_agent **arr, int size, sort_by f);
sort_by mx_get_sort_by_from_flag(char *flag);
