/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		display_utils.c
*/

#include "../include/rpg.h"
#include "../include/my.h"

// f) d'affichage des stats de l'enemy
void display_stats_enemy(Enemy_t *enemy_arr)
{
    my_putstr("\033[0;31m");
    my_putstr("\t\t\tEnemy -> ");
    my_putstr(enemy_arr->name);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;33m");
    my_putstr("\t\t\tHP : ");
    my_putstr("\033[0m");
    my_putstr("\033[0;32m");
    my_putnbr(enemy_arr->hp);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;33m");
    my_putstr("\t\t\tStrength : ");
    my_putstr("\033[0m");
    my_putstr("\033[0;31m");
    my_putnbr(enemy_arr->str);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;33m");
    my_putstr("\t\t\tDefense : ");
    my_putstr("\033[0m");
    my_putstr("\033[0;40m");
    my_putnbr(enemy_arr->def);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("\033[0;36m");
    my_putstr("======================= VS ========================\n");
    my_putstr("\033[0m");
}

// f) d'affichage des stats du player
void display_stats_player(Player_t *player_arr)
{
    my_putstr("\033[0;34m");
    my_putstr("Player -> ");
    my_putstr(player_arr->name);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("XP : ");
    my_putnbr(player_arr->xp);
    my_putstr("  Rank : ");
    my_putnbr(player_arr->rank);
    my_putchar('\n');
    my_putstr("HP : ");
    my_putstr("\033[0m");
    my_putstr("\033[0;32m");
    my_putnbr(player_arr->hp);
    my_putstr("\033[0m");
    my_putstr(" / ");
    my_putstr("\033[0;35m");
    my_putnbr(player_arr->hp_max);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;36m");
    my_putstr("Strength : ");
    my_putstr("\033[0m");
    my_putstr("\033[0;31m");
    my_putnbr(player_arr->str);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;36m");
    my_putstr("Defense : ");
    my_putstr("\033[0m");
    my_putnbr(player_arr->def);
    my_putchar('\n');
}

// f) d'affichage des stats du boss
void display_stats_boss(Boss_t *boss_arr)
{
    my_putstr("\033[0;35m");
    my_putstr("\t\t\tBoss -> ");
    my_putstr(boss_arr->name);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;31m");
    my_putstr("\t\t\tHP : ");
    my_putnbr(boss_arr->hp);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;31m");
    my_putstr("\t\t\tStrength : ");
    my_putnbr(boss_arr->str);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;31m");
    my_putstr("\t\t\tDefense : ");
    my_putnbr(boss_arr->def);
    my_putstr("\033[0m");
    my_putchar('\n');
    my_putstr("\033[0;36m");
    my_putstr("======================= VS ========================\n");
    my_putstr("\033[0m");
}

void display_info_enemy(Player_t *player, Enemy_t *enemy)
{
    display_stats_enemy(enemy);
    display_stats_player(player);
}

void display_info_boss(Player_t *player, Boss_t *boss)
{
    display_stats_boss(boss);
    display_stats_player(player);
}
