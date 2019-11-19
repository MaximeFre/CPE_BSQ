/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** header
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct biggest
{
    int big;
    int y;
    int x;
} biggest_t;

int my_getnbr(char const *str);
char *open_file(char const *filepath);
int **str_to_arr(char *file, int nb, int *length);
