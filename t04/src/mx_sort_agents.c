#include "../inc/agent.h"

static bool by_strength(t_agent *a, t_agent *b) {
    return a->strength > b->strength;
}

static bool by_power(t_agent *a, t_agent *b) {
    return a->power > b->power;
}

static bool by_name(t_agent *a, t_agent *b) {
    return mx_strcmp(a->name, b->name) > 0; // or < 0 ??
}

sort_by mx_get_sort_by_from_flag(char *flag) {
    if (!flag) return NULL;
    if (mx_strcmp(flag, NAME_FLAG) == 0) {
        return by_name;
    }
    else if (mx_strcmp(flag, POWER_FLAG) == 0) {
        return by_power;
    }
    else if (mx_strcmp(flag, STRENGTH_FLAG) == 0) {
        return by_strength;
    }
    return NULL;
}

void mx_sort_agents(t_agent **arr, int size, sort_by f) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (!f(arr[j], arr[j + 1])) {
                continue;
            }

            t_agent *temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
