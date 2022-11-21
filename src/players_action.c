/*
** ETNA PROJECT, 2022
** MY_RPG
** File description
** 		character_action.c
*/

#include "../include/rpg.h"
#include "../include/my.h"

int random_num(const int min,const int max);
void init_random();

// f) qui initialise un nouveau player
Player_t *new_player(Player_t *player_arr)
{
    Player_t *new_players;

    new_players = malloc(sizeof(Player_t));     
    new_players->name = my_strdup(player_arr->name);
    new_players->hp = player_arr->hp;
    new_players->str = player_arr->str;
    new_players->mp = player_arr->mp;
    new_players->inte = player_arr->inte;
    new_players->def = player_arr->def;
    new_players->res = player_arr->res;
    new_players->spd = player_arr->spd;
    new_players->luck = player_arr->luck;
    new_players->hp_max = player_arr->hp_max;
            
    return (new_players);
}

int critical_luck(Player_t **player)
{
    int num;

    init_random();
    num = random_num(1, 100);
    if(num < (*player)->luck){
        my_putstr("You inflict a critical damage\n");
        return 2;
    }else{
        return 1;
    }
}

//f) attaque qui soustrait les str p_a des hp de enem_a
void attack_player(Player_t **player_a, Enemy_t **enemy_a)
{
    int crit;

    crit = critical_luck(player_a);
    (*enemy_a)->hp = (*enemy_a)->hp - ((*player_a)->str * crit) + ((*enemy_a)->def/100);
    my_putstr("You attack and do  : ");
    my_putnbr((*player_a)->str * crit);
    my_putstr(" dammage.");
    my_putchar('\n');

}

//f) attaque qui soustrait les str p_a des hp de enem_a
void attack_player_boss(Player_t **player_a, Boss_t **boss)
{
    //(*boss)->hp = (*boss)->hp - (*player_a)->str;
    (*boss)->hp = (*boss)->hp - (*player_a)->str + ((*boss)->def/100);
    my_putstr("You attack and do  : ");
    my_putnbr((*player_a)->str);
    my_putstr(" dammage.");
    my_putchar('\n');
}

//f) soins qui ajoute les hp init divisé par 2
void heal_player(Player_t **player_a)
{
    if((*player_a)->hp > (*player_a)->hp_max/2 ){
        (*player_a)->hp += (*player_a)->hp_max - (*player_a)->hp;
        my_putstr("You use heal, you now have : ");
        my_putnbr((*player_a)->hp);
        my_putstr(" / ");
        my_putnbr((*player_a)->hp_max);
        my_putchar('\n');
    }else{
        (*player_a)->hp += ((*player_a)->hp_max)/2;
        my_putstr("You use heal, you now have : ");
        my_putnbr((*player_a)->hp);
        my_putstr(" / ");
        my_putnbr((*player_a)->hp_max);
        my_putchar('\n');
    } 
}
