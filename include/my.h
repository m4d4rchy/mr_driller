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
#include <SFML/Config.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

sfRenderWindow *create_window(char *, int, int);

int gameloop (sfRenderWindow *, sfEvent);

sfSprite *my_sprite(const char*);

int start_menu (sfRenderWindow *, sfEvent);

int logo_display (sfRenderWindow *, sfEvent);

int **my_createboard();