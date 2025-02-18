#include "../inc/agent.h"

t_agent *mx_create_agent(char *name, int power, int strength) {
    if (!name || power < 0 || strength < 0) {
        return NULL;
    }

    t_agent *agent = malloc(sizeof(t_agent));

    if (!agent) return NULL;

    char *name_clone = mx_strdup(name); 

    if (!name_clone) {
        free(agent);
    }

    agent->name = name_clone;
    agent->power = power;
    agent->strength = strength;

    free(name_clone);

    return agent;
}
