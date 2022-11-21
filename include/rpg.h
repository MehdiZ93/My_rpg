#ifndef RPG_H_
#define RPG_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Player {
    const char *name;
    int hp;
    int mp;
    int str;
    int str_init;
    int inte;
    int def;
    int res;
    int spd;
    int luck;
    int hp_max;
    int xp;
    int rank;
    int xp_to_up;
} Player_t;


typedef struct Enemy_s
{
    char *name;
    int hp;
    int mp;
    int str;
    int inte;
    int def;
    int res;
    int spd;
    int luck;
}Enemy_t;

typedef struct Boss_s
{
    char *name;
    int hp;
    int mp;
    int str;
    int inte;
    int def;
    int res;
    int spd;
    int luck;
}Boss_t;

#endif /* !RPG_H_ */
