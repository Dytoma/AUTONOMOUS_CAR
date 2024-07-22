/*
** EPITECH PROJECT, 2024
** B-AIA-200-TLS-2-1-n4s-dytoma.batogouma
** File description:
** main
*/

#include "ai.h"

static char **init_commands(void)
{
    char **cmds = malloc(sizeof(char *) * (13));

    cmds[0] = strdup("START_SIMULATION");
    cmds[1] = strdup("STOP_SIMULATION");
    cmds[2] = strdup("CAR_FORWARD");
    cmds[3] = strdup("CAR_BACKWARDS");
    cmds[4] = strdup("WHEELS_DIR");
    cmds[5] = strdup("GET_INFO_LIDAR");
    cmds[6] = strdup("GET_CURRENT_SPEED");
    cmds[7] = strdup("GET_CURRENT_WHEELS");
    cmds[8] = strdup("CYCLE_WAIT");
    cmds[9] = strdup("GET_CAR_SPEED_MAX");
    cmds[10] = strdup("GET_CAR_SPEED_MIN");
    cmds[11] = strdup("GET_INFO_SIMTIME");
    cmds[12] = NULL;
    return cmds;
}

int main(void)
{
    char **cmds = init_commands();

    if (cmds == NULL)
        return 84;
    send_commands(cmds);
    destroy_arr(cmds);
    return 0;
}
