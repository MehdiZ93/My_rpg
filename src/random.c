/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		random.c
*/

#include <time.h>
#include <stdlib.h>

void init_random()
{
    srand(time(NULL));
}

int random_num(const int min, const int max)
{
    return (rand() % max + min);
}
