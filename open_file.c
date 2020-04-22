/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
** open file
*/

#include "include/my.h"

int line_length(char *file)
{
    int a = 0;
    int i = 0;

    for (i = 0; file[i] != '\n'; i++);
    i++;
    for (; file[i] != '\n'; i++)
        a++;
    return (a);
}

int **str_to_arr(char *file, int nb, int *length)
{
    int **map = malloc(sizeof(int *) * (nb + 1));
    int i = 0;

    *length = line_length(file);
    map[nb] = NULL;
    for (i = 0; file[i] != '\n'; i++);
    i++;
    for (int a = 0; a < nb; a++) {
        map[a] = malloc(sizeof(int) * (*length));
        for (int z = 0; z < *length; i++, z++) {
            if (file[i] == 'o')
                map[a][z] = 0;
            else
                map[a][z] = 1;
        }
        i++;
    }
    return (map);
}

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    long long size;
    struct stat *buf = malloc(sizeof(struct stat));
    char *map;

    if (stat(filepath, buf) == 0)
        size = buf->st_size;
    else
        return (NULL);
    map = malloc(sizeof(char) * (size + 1));
    read(fd, map, size);
    map[size] = '\0';
    free(buf);
    return (map);
}
