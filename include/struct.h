/*
 * Filename: struct.h
 * Project: mr_driller
 * Created Date: Tuesday, December 18th 2018, 11:16:25 am
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_mainmenu
{
    sfSprite *logo;
    sfVector2f logo_position;
    sfClock *logo_clock;
    sfTime logo_time;
    sfSprite *background;
    sfSprite *image;
    sfSprite **circle;
    sfVector2f *circle_position;
    sfIntRect circle_area1;
    sfIntRect circle_area2;
    sfIntRect circle_area3;
    sfClock *circle_clock;
    sfTime circle_time;
    sfFont *font;
    sfText *message;
    sfVector2f message_position;
    sfClock *message_clock;
    sfTime message_time;
    sfMusic *music;
    sfMusic *sfx;

} t_startmenu;

typedef struct s_game
{
    sfSprite *background;
    sfSprite *gamegui;
    sfVector2f gamegui_position;
    sfSprite ***blocks;
    sfSprite *player;
    sfVector2f player_position;
    sfMusic *music;
    sfClock *clock;
    sfTime time;
    sfText  **text;
    int depth;
    int score;
    int air;
    int level;
    float seconds;
    int *player_block_pos;
} t_game;

typedef struct s_logo
{
    sfSprite *logo;
    sfColor color;
    sfClock *clock;
    sfTime fade;
} t_logo;

#endif