/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		create_function.c
*/


#include <stdio.h>
#include "../include/rpg.h"

Player_t *new_player(Player_t *player_arr);
Enemy_t *new_enemy(Enemy_t *enemy_arr);
Boss_t *new_boss(Boss_t *boss_arr);
int random_num(const int min, const int max);
int player_arraylen(Player_t **arr);
int boss_arraylen(Boss_t **arr);
int enemy_arraylen(Enemy_t **arr);
void init_random();

Player_t *create_player(Player_t **player_arr)
{
    int random_index;

    init_random();
    random_index = random_num(0, player_arraylen(player_arr) - 1);
    return (new_player(player_arr[random_index]));
}

Enemy_t *create_enemy(Enemy_t **enemy_arr)
{
    int random_index;
    
    init_random();
    random_index = random_num(0, enemy_arraylen(enemy_arr) - 1);
    return (new_enemy(enemy_arr[random_index]));
}

Boss_t *create_boss(Boss_t **boss_arr)
{
    int random_index;

    init_random();
    random_index = random_num(0, boss_arraylen(boss_arr) - 1);
    return (new_boss(boss_arr[random_index]));
}
