/*
 ** ETNA PROJECT, 2022
 ** MY_RPG
 ** File description
 ** 		main.c
 */

#include <stdlib.h>
#include "../include/my.h"
#include "../include/rpg.h"

int init_game(const int floors);

int floor_number()
{
    char *user_choice;

    my_putstr("How many floors do you want ?\n");
    my_putstr("1 - 10 floor\t2 - 20 floor\t3 - 50 floors\t4 - 100 floors\n");
    user_choice = my_readline();
    while (!user_choice || (my_strcmp(user_choice, "1") &&
                            my_strcmp(user_choice, "2") &&
                            my_strcmp(user_choice, "3") &&
                            my_strcmp(user_choice, "4"))) {
        free(user_choice);
        user_choice = my_readline();
    }
    if (my_strcmp(user_choice, "1") == 0) {
        free(user_choice);
        return (10);
    } else if (my_strcmp(user_choice, "2") == 0) {
        free(user_choice);
        return (20);
    } else if (my_strcmp(user_choice, "3") == 0) {
        free(user_choice);
        return (50);
    }
    free(user_choice);
    return (100);
}

int menu()
{
    char *user_choice;

    my_putstr("\033[0;35m");
    my_putstr("1 - New Game\t");
    my_putstr("\033[0m");
    my_putstr("\033[0;32m");
    my_putstr("2 - Quit\n");
    my_putstr("\033[0m");
    user_choice = my_readline();
    while (!user_choice || (my_strcmp(user_choice, "1") && my_strcmp(user_choice, "2"))) {
        free(user_choice);
        user_choice = my_readline();
    }
    if (my_strcmp(user_choice, "2") == 0) {
        free(user_choice);
        return (0);
    }
    free(user_choice);
    return (floor_number());
}

void game_start(const int floors)
{
    my_putstr("\e[1;1H\e[2J");
    my_putstr("Game start\n");
    init_game(floors);
}

int main()
{
    int floors;

    my_putstr("\e[1;1H\e[2J");
    floors = menu();
    if (floors > 0)
        game_start(floors);
}
