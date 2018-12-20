/*
 * Filename: struct.h
 * Project: mr_driller
 * Created Date: Tuesday, December 18th 2018, 11:16:25 am
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2018 Yassine Benmessahel
 */

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_startmenu
{
    sfSprite *logo;
    sfVector2f logo_position;
    sfClock *logo_clock;
    sfTime logo_time;
    sfSprite *background;
    sfSprite *image;
    sfSprite **circle;
    sfVector2f *circle_position;
    sfIntRect circle_area;
    sfClock *circle_clock;
    sfTime circle_time;
    sfFont *font;
    sfText *message;
    sfVector2f message_position;
    sfClock *message_clock;
    sfTime message_time;
    sfMusic* music;
    sfMusic* sfx;

} t_startmenu;

typedef struct s_logo
{
    sfSprite *logo;
    sfColor color;
    sfClock *clock;
    sfTime fade;
} t_logo;

#endif