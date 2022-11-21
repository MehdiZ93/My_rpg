/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		fight.c
*/

#include "../include/my.h"
#include "../include/rpg.h"

void heal_player(Player_t **player_a);
void attack_player(Player_t **player_a, Enemy_t **enemy_a);
void heal_player(Player_t **player_a);
void attack_enemy(Enemy_t **enemy_a, Player_t **player_a);
void attack_boss(Boss_t **boss_a, Player_t **player_a);
void attack_player_boss(Player_t **player_a, Boss_t **boss);
void display_info_boss(Player_t *player, Boss_t *boss);
void display_info_enemy(Player_t *player, Enemy_t *enemy);
int random_num(const int min,const int max);
void init_random();
void add_xp(Player_t **player);

int player_action()
{
    char *player_choice;

    my_putstr("\033[0;31m");
    my_putstr("1 - Attack\t");
    my_putstr("\033[0m");
    my_putstr("\033[0;32m");
    my_putstr("2 - Heal\n");
    my_putstr("\033[0m");
    player_choice = my_readline();
    while (!player_choice || (my_strcmp(player_choice, "1") && my_strcmp(player_choice, "2")))
    {
        free(player_choice);
        player_choice = my_readline();
    }
    if (my_strcmp(player_choice, "1") == 0)
    {
        free(player_choice);
        return (1);
    }
    free(player_choice);
    return (2);
}

void fight_enemy(Player_t **player, Enemy_t **enemy)
{
    while ((*enemy)->hp > 0 && (*player)->hp > 0)
    {
        display_info_enemy(*player, *enemy);
        my_putstr("\x1b[33m");
        my_putstr("========== Attack like a man or heal you ==========\n");
        my_putstr("\033[0m");

        if (player_action() == 1)
            attack_player(player, enemy);
        else
            heal_player(player);
        if ((*enemy)->hp > 0)
            attack_enemy(enemy, player);
        free(my_readline());
        my_putstr("\e[1;1H\e[2J");
    }
    if ((*enemy)->hp <= 0)
        add_xp(player);
}

void fight_boss(Player_t **player, Boss_t **boss)
{
    while ((*boss)->hp > 0 && (*player)->hp > 0)
    {

        display_info_boss(*player, *boss);
        my_putstr("\x1b[33m");
        my_putstr("========== Attack like a man or heal you ==========\n");
        my_putstr("\033[0m");
        if (player_action() == 1)
            attack_player_boss(player, boss);
        else
            heal_player(player);
        if ((*boss)->hp > 0)
            attack_boss(boss, player);
        my_putstr("\e[1;1H\e[2J");
    }
    if ((*boss)->hp <= 0)
    {
        my_putstr("\x1b[33m");
        my_putstr("Well done my friend you burst it well:");
        my_putstr("\033[0m");
        my_putstr((*boss)->name);
        my_putstr("!\n");
    }
}
