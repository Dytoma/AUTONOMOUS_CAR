/*
** EPITECH PROJECT, 2024
** B-AIA-200-TLS-2-1-n4s-dytoma.batogouma
** File description:
** ai
*/

#ifndef AI_H_
    #define AI_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <sys/types.h>

typedef enum cmd_s {
    START = 0,
    STOP,
    CAR_F,
    CAR_B,
    WHEEL_DIR,
    INFO_LIDAR,
    CURRENT_SPEED,
    CURRENT_WHELLS,
    CYCLE,
    SPEED_MAX,
    SPEED_MIN,
    SIMTIME
} cmd_t;

char **my_str_to_word(char *str, char *delim);
void send_commands(char **cmds);
void destroy_arr(char **arr);
int arr_len(char **arr);

#endif /* !AI_H_ */
