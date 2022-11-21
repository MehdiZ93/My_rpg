/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		boss_action.c
*/

#include "../include/rpg.h"
#include "../include/my.h"
#include <stdio.h>

int random_num(const int min,const int max);
void init_random();

// f) qui initialise un nouveau boss
Boss_t *new_boss(Boss_t *boss_arr)
{
    Boss_t *new_boss;

    new_boss = malloc(sizeof(Boss_t));
    new_boss->name = my_strdup(boss_arr->name);
    new_boss->hp = boss_arr->hp;
    new_boss->str = boss_arr->str;
    new_boss->mp = boss_arr->mp;
    new_boss->inte = boss_arr->inte;
    new_boss->def = boss_arr->def;
    new_boss->res = boss_arr->res;
    new_boss->spd = boss_arr->spd;
    new_boss->luck = boss_arr->luck;
            
    return (new_boss);
}

int critical_luck_boss(Boss_t **boss)
{
    int num;

    init_random();
    num = random_num(1, 100);
    if(num < (*boss)->luck){
        return 2;
    }else{
        return 1;
    }
}

//f) attaque qui soustrait les str p_a des hp de enem_a
void attack_boss(Boss_t **boss_a, Player_t **player_a)
{
    //(*player_a)->hp = (*player_a)->hp - (*boss_a)->str;
    (*player_a)->hp = (*player_a)->hp - ((*boss_a)->str*critical_luck_boss(boss_a)) + ((*player_a)->def/100);
    my_putstr((*boss_a)->name);
    my_putstr("  attack and do  : ");
    my_putnbr((*boss_a)->str);
    my_putstr(" dammage.");
    my_putchar('\n');
}
