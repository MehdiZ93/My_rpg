/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		enemies_action.c
*/

#include "../include/rpg.h"
#include "../include/my.h"

int random_num(const int min,const int max);
void init_random();

// f) qui initialise un nouveau enemy
Enemy_t *new_enemy(Enemy_t *enemy_arr)
{
    Enemy_t *new_enemys;

    new_enemys = malloc(sizeof(Enemy_t));
    new_enemys->name = my_strdup(enemy_arr->name);
    new_enemys->hp = enemy_arr->hp;
    new_enemys->str = enemy_arr->str;
    new_enemys->mp = enemy_arr->mp;
    new_enemys->inte = enemy_arr->inte;
    new_enemys->def = enemy_arr->def;
    new_enemys->res = enemy_arr->res;
    new_enemys->spd = enemy_arr->spd;
    new_enemys->luck = enemy_arr->luck;            
    return (new_enemys);
}

int critical_luck_enemy(Enemy_t **enemy)
{
    int num;

    init_random();
    num = random_num(1, 100);
    if(num < (*enemy)->luck){
        return 2;
    }else{
        return 1;
    }
}

//f) attaque qui soustrait les str enem_a des hp de p_a
void attack_enemy(Enemy_t **enemy_a, Player_t **player_a)
{
    //(*player_a)->hp = (*player_a)->hp - (*enemy_a)->str;
    (*player_a)->hp = (*player_a)->hp - ((*enemy_a)->str*critical_luck_enemy(enemy_a)) + ((*player_a)->def/100);
    my_putstr((*enemy_a)->name);
    my_putstr("  attack and do  : ");
    my_putnbr((*enemy_a)->str);
    my_putstr(" dammage.");
    my_putchar('\n');
}
