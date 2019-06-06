/*
 * Filename: my.h
 * Project: mr_driller
 * Created Date: Monday, December 17th 2018, 4:51:21 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

#ifndef MY_H_
#define MY_H_

sfRenderWindow *create_window (char *, int, int);
sfText *create_texte(char *str, char *fontpath, int size);

/*  game.c  */
int gameloop (sfRenderWindow *, sfEvent);
int **createboard (void);
sfSprite ***initialize_game (int **);
int player_movement(t_game *element, sfKeyCode code);
int drillBlock(const char *direction, t_game *element);
void moveBoard(t_game *element);
void collisionCheck(sfRenderWindow *window, sfEvent event, t_game *element);

/*  gameui.c  */
int print_gameui(t_game *);

/*  mapgenerate.c  */
sfSprite ***createBlock (int **);
int **genBlock(void);

/*  scorescreen.c  */

/*  main.c  */
sfSprite *my_sprite (const char *);
sfSprite *my_sprite_rec (const char *, sfIntRect);

/*  main_menu.c  */
int main_menu (sfRenderWindow *, sfEvent);
int blink_effect (sfRenderWindow *, t_startmenu *);
int logo_drop (sfRenderWindow *, t_startmenu *);
int circle_animation (sfRenderWindow *, t_startmenu *);

/*  splashscreen.c  */
int splashscreen (sfRenderWindow *, sfEvent);

/*  initialization.c  */
struct s_mainmenu main_menu_init (void);
struct s_game gameloop_init(void);
struct s_logo logo_display_init (void);
#endif
