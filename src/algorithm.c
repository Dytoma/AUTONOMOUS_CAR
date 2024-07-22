/*
** EPITECH PROJECT, 2024
** B-AIA-200-TLS-2-1-n4s-dytoma.batogouma
** File description:
** algorithm
*/

#include "ai.h"

void destroy_arr(char **arr)
{
    if (arr == NULL || arr[0] == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    return;
}

static void change_speed(char **cmds, double speed)
{
    char *lineptr = NULL;
    size_t n = 0;

    dprintf(1, "%s:%f\n", cmds[CAR_F], speed);
    getline(&lineptr, &n, stdin);
    free(lineptr);
    return;
}

static void change_dir(char **cmds, double angle)
{
    char *lineptr = NULL;
    size_t n = 0;

    dprintf(1, "%s:%f\n", cmds[WHEEL_DIR], angle);
    getline(&lineptr, &n, stdin);
    free(lineptr);
    return;
}

void stop_car(char **cmds)
{
    char *lineptr = NULL;
    size_t n = 0;

    dprintf(1, "%s\n", cmds[STOP]);
    getline(&lineptr, &n, stdin);
    free(lineptr);
    return;
}

static int obstacle_right(char **cmds, double fst, double snd)
{
    if (fst > 30.0 && fst < 300.0) {
        change_dir(cmds, 0.0425);
        return 0;
    } else if (fst >= 300.0 && fst < 500.0) {
        change_dir(cmds, 0.0725);
        return 0;
    }
    if (fst >= 500.0) {
        change_dir(cmds, 0.13);
        return 0;
    }
}

static int obstacle_left(char **cmds, double fst, double snd)
{
    if (snd > 30.0 && snd < 250.0) {
        change_dir(cmds, -0.0425);
        return 0;
    } else if (snd >= 250.0 && snd < 500.0) {
        change_dir(cmds, -0.0725);
        return 0;
    }
    if (snd >= 500.0) {
        change_dir(cmds, -0.13);
    } else
        change_dir(cmds, 0.0);
    return 0;
}

static void pos_brand(char **arr, char **cmds, char **line, size_t *n)
{
    float fst = 0.0;
    float snd = 0.0;

    fst = atof(arr[3]) - atof(arr[34]);
    snd = atof(arr[34]) - atof(arr[3]);
    if (atof(arr[18]) <= 525.0 && fst < 0.0) {
        change_speed(cmds, 0.1);
        change_dir(cmds, -0.4);
        return;
    } else if (atof(arr[18]) <= 525.0 && snd < 0.0) {
        change_speed(cmds, 0.1);
        change_dir(cmds, 0.4);
        return;
    } else
        change_speed(cmds, 0.245);
    if (obstacle_right(cmds, fst, snd) == 0)
        return;
    obstacle_left(cmds, fst, snd);
}

int check_track(char **arr, char **cmds)
{
    if (arr == NULL || arr[0] == NULL)
        return 1;
    if (strcmp(arr[arr_len(arr) - 2], "Track Cleared") == 0) {
        change_speed(cmds, 0.0);
        destroy_arr(arr);
        return 0;
    }
    return 1;
}

int start_simulation(char **cmds)
{
    char *lineptr = NULL;
    size_t n = 0;
    char **arr = NULL;

    dprintf(1, "%s\n", cmds[START]);
    if (getline(&lineptr, &n, stdin) == -1)
        return 1;
    arr = my_str_to_word(lineptr, ":\n");
    if (strcmp(arr[1], "KO") == 0) {
        destroy_arr(arr);
        free(lineptr);
        return 1;
    }
    return 0;
}

void send_commands(char **cmds)
{
    char *lineptr = NULL;
    size_t n = 0;
    char **arr = NULL;

    if (start_simulation(cmds))
        return;
    change_speed(cmds, 0.27);
    while (1) {
        dprintf(1, "%s\n", cmds[INFO_LIDAR]);
        getline(&lineptr, &n, stdin);
        arr = my_str_to_word(lineptr, ":");
        if (check_track(arr, cmds) == 0)
            break;
        pos_brand(arr, cmds, &lineptr, &n);
        destroy_arr(arr);
    }
    stop_car(cmds);
    return;
}
