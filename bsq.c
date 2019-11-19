/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** bsq
*/

#include "include/my.h"

int line_checking(char *file)
{
    int length = 0;
    int baselength = 0;

    while (*file != '\n')
        file++;
    file++;
    for (; *file != '\n'; file++, baselength++);
    file++;
    while (*file != '\0') {
        length = 0;
        for (; *file != '\n'; file++, length++);
        if (length != baselength)
            return (84);
        file++;
    }
    return (0);
}

int error_handling(char *file)
{
    int i = 0;
    int count = 0;

    for (int a = 0; file[a]; a++) {
        if (file[a] == '\n')
            count++;
    }
    if (my_getnbr(file) != (count - 1))
        return (84);
    for (; file[i] != '\n'; i++) {
        if (file[i] > '9' || file[i] < '0')
            return (84);
    }
    i++;
    for (; file[i]; i++) {
        if (file[i] != '.' && file[i] != 'o' && file[i] != '\n')
            return (84);
    }
    return (0);
}

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
    char *file;
    int line;
    int **map;

    if (ac != 2)
        return (84);
    file = open_file(av[1]);
    if (error_handling(file) == 84)
        return (84);
    line = my_getnbr(file);
    if (line_checking(file) == 84)
        return (84);
    map = str_to_arr(file, line, &length);
    bsq(map, line, length, file);
    return (0);
}
