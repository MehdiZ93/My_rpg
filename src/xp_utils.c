/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		xp_utils.c
*/

#include "../include/my.h"
#include "../include/rpg.h"

void init_random();
int random_num(const int min , const int max);

void level_up(Player_t **player)
{
    int num;

    (*player)->rank += 1;
    (*player)->xp -= (*player)->xp_to_up;
    (*player)->xp_to_up += (*player)->rank - 1;
    init_random();
    num = random_num(1, 3);
    if (num == 1)
    {
        (*player)->hp += 5;
        (*player)->hp_max += 5;
    }
    else if (num == 2)
    {
        (*player)->str += 2;
    }
    else if (num == 3)
    {
        (*player)->def += 1;
    }
}

void add_xp(Player_t **player)
{
    int xp;

    init_random();
    xp = random_num(1, 50);
    (*player)->xp += xp;
    if((*player)->xp >= (*player)->xp_to_up){
        level_up(player);
    }
}
