/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** bsq
*/

#include "include/my.h"

void print_map(char *file, biggest_t *biggest, int line, int length)
{
    int count = 0;

    while (*file != '\n')
        file++;
    file++;
    if (line == 1 || length == 1) {
        for (int z = 0; file[z] != '\0'; z++) {
            if (file[z] == '.' && count == 0) {
                file[z] = 'x';
                count = 1;
            }
        }
    }
    for (int i = 0; i < biggest->big; i++) {
        for (int a = 0; a < biggest->big; a++) {
            file[((length + 1) * (biggest->y - i)) + (biggest->x - a)] = 'x';
        }
    }
    write(1, file, (line * length + line));
}

int bsq(int **map, int line, int length, char *file)
{
    biggest_t *biggest = malloc(sizeof(biggest_t));

    biggest->big = 0;
    biggest->y = 0;
    biggest->x = 0;
    for (int i = 1; i < line; i++) {
        for (int a = 1; a < length; a++) {
            if (map[i][a] > 0)
                map[i][a] += MIN(MIN(map[i][a - 1], map[i - 1][a]),
                map[i - 1][a - 1]);
            if (map[i][a] > biggest->big) {
                biggest->big = map[i][a];
                biggest->y = i;
                biggest->x = a;
            }
        }
    }
    print_map(file, biggest, line, length);
    return (0);
}

int main(int ac, char **av)
{
    int length = 0;
    char *file = open_file(av[1]);
    int line = my_getnbr(file);
    int **map = str_to_arr(file, line, &length);
    return (bsq(map, line, length, file));
}
