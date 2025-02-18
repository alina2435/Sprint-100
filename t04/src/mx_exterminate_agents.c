#include "../inc/agent.h"

void mx_exterminate_agents(t_agent ***agents) {
    if (!agents || !*agents) return;
    for (int i = 0; (*agents)[i] != NULL; i++) {
        free((*agents)[i]->name);
        free((*agents)[i]);
    }
    free(*agents);
    *agents = NULL;
}
