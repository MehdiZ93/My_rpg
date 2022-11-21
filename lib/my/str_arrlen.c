/*
** ETNA PROJECT, 2022
** libmy
** File description
** 		str_arrlen.c
*/

int str_arrlen(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i = i + 1;
    return (i);
}
