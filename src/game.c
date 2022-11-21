/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		game.c
*/

#include "../include/rpg.h"
#include "../include/my.h"

Player_t *create_player(Player_t **player_arr);
Enemy_t *create_enemy(Enemy_t **enemy_arr);
void fight_enemy(Player_t **player, Enemy_t **enemy);
Enemy_t **init_enemies(void);
Player_t **init_player(void);
Boss_t **init_Boss(void);
Boss_t *create_boss(Boss_t **boss_arr);
void fight_boss(Player_t **player, Boss_t **boss);
void init_random();

int game(Player_t **player_arr, Enemy_t **enemy_arr, Boss_t **boss_arr, const int floors)
{
    int curr_floor;
    Player_t *player;
    Enemy_t *enemy;
    Boss_t *boss;

    curr_floor = 1;
    player = create_player(player_arr);
    while (curr_floor <= floors && player->hp > 0) {
        if (curr_floor % 10 > 0) {
            enemy = create_enemy(enemy_arr);
            fight_enemy(&player, &enemy);
            free(enemy->name);
            free(enemy);
        } else if (curr_floor % 10 == 0) {
            boss = create_boss(boss_arr);
            fight_boss(&player, &boss);
            free(boss->name);
            free(boss);

        }
        if (player->hp <= 0) {
            my_putstr("\033[0;30m");
            my_putstr("YOU LOSE, Go play with dolls it's better for you\n");
            my_putstr("\033[0m");
        }
        curr_floor = curr_floor + 1;
    }
    if (player->hp > 0) {
        my_putstr("\033[1;31m");
        my_putstr("Congratulation, You have defeated all your enemies !\n");
        my_putstr("\033[0m");
    }
    free((char*)player->name);
    free(player);
    return (0);
}

void free_arrays(Player_t **player_arr, Enemy_t **enemy_arr, Boss_t **boss_arr)
{
    int i;

    i = 0;
    while (player_arr[i]) {
        free((char*)player_arr[i]->name);
        free(player_arr[i]);
        i = i + 1;
    }
    free(player_arr);
    i = 0;
    while (enemy_arr[i]) {
        free(enemy_arr[i]->name);
        free(enemy_arr[i]);
        i = i + 1;
    }
    free(enemy_arr);
    i = 0;
    while (boss_arr[i]) {
        free(boss_arr[i]->name);
        free(boss_arr[i]);
        i = i + 1;
    }
    free(boss_arr);
}

int init_game(const int floors)
{
    Player_t **player_arr;
    Enemy_t **enemy_arr;
    Boss_t **boss_arr;

    player_arr = init_player();
    enemy_arr = init_enemies();
    boss_arr = init_Boss();
    if (player_arr && enemy_arr && boss_arr) {
        game(player_arr, enemy_arr, boss_arr, floors);
        free_arrays(player_arr, enemy_arr, boss_arr);
        return (0);
    } else {
        my_putstr("Could not create arrays");
        return (1);
    }
}
