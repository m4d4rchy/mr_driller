/*
 * Filename: initialization.c
 * Project: mr_driller
 * Created Date: Thursday, December 20th 2018, 10:47:47 am
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2018 Yassine Benmessahel
 */

#include "my.h"

struct s_startmenu start_menu_init(void)
{
    t_startmenu element;

    element.background = my_sprite("img/menubg.jpg");
    element.logo = my_sprite("img/logomenu.png");
    element.logo_position.x = 35;
    element.logo_position.y = -270;
    element.logo_clock = sfClock_create();
    element.image = my_sprite("img/circlebg.png");
    element.circle_position = malloc(sizeof (element.circle) * 3);
    element.circle = malloc(sizeof (*element.circle) * 3);
    element.circle[0] = my_sprite("img/circle_spritesheet.png");
    element.circle[1] = my_sprite("img/circle_spritesheet.png");
    element.circle[2] = my_sprite("img/circle_spritesheet.png");
    element.circle_position[0].x = 650;
    element.circle_position[0].y = 180;
    sfSprite_setPosition(element.circle[0], element.circle_position[0]);
    element.circle_position[1].x = -50;
    element.circle_position[1].y = 280;
    sfSprite_setPosition(element.circle[1], element.circle_position[1]);
    element.circle_position[2].x = 650;
    element.circle_position[2].y = 380;
    sfSprite_setPosition(element.circle[2], element.circle_position[2]);
    element.circle_clock = sfClock_create();
    element.font = sfFont_createFromFile("font/retro.ttf");
    element.message = sfText_create();
    element.message_position.x = 115;
    element.message_position.y = 500;
    element.message_clock = sfClock_create();
    element.music = sfMusic_createFromFile("sound/menu.ogg");
    sfText_setPosition(element.message, element.message_position);
    sfSprite_setPosition(element.logo, element.logo_position);
    sfText_setFont(element.message, element.font);
    sfText_setString(element.message, "PRESS ANY KEY TO START");
    return (element);
}

struct s_logo logo_display_init(void)
{
    t_logo element;

    element.logo = my_sprite("img/Namco-Logo.jpg");
    element.clock = sfClock_create();
    element.color.r = 255;
    element.color.g = 255;
    element.color.b = 255;
    element.color.a = 0;
    sfSprite_setColor(element.logo, element.color);
    return (element);
}