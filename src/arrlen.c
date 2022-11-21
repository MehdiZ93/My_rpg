/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		arrlen.c
*/

#include "../include/rpg.h"

int player_arraylen(Player_t **arr)
{
    int i;

    i = 0;
    while (arr[i]) {
        i =  i + 1;
    }
    return (i);
}

int boss_arraylen(Boss_t **arr)
{
    int i;

    i = 0;
    while (arr[i]) {
        i =  i + 1;
    }
    return (i);
}

int enemy_arraylen(Enemy_t **arr)
{
    int i;

    i = 0;
    while (arr[i]) {
        i =  i + 1;
    }
    return (i);
}
