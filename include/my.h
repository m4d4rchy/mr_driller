/*
 * Filename: my.h
 * Project: mr_driller
 * Created Date: Monday, December 17th 2018, 4:51:21 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2018 Yassine Benmessahel
 */

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#ifndef MY_H_
#define MY_H_

sfRenderWindow *create_window (char *, int, int);

/*  game.c  */
int gameloop (sfRenderWindow *, sfEvent);
int **my_createboard (void);
int logo_display (sfRenderWindow *, sfEvent);
sfSprite ***initialize_game (int **);

/*  main.c  */
sfSprite *my_sprite (const char *);
sfSprite *my_sprite_rec (const char *, sfIntRect);

/*  main_menu.c  */
int start_menu (sfRenderWindow *, sfEvent);
int blink_effect (sfRenderWindow *, t_startmenu *);
int logo_animation (sfRenderWindow *, t_startmenu *);
int circle_animation (sfRenderWindow *, t_startmenu *);

/*  initialization.c  */
struct s_startmenu start_menu_init (void);
struct s_game gameloop_init(void);
struct s_logo logo_display_init (void);
#endif
