/*
 * Filename: scorescreen.c
 * Project: mr_driller
 * Created Date: Saturday, May 25th 2019, 8:39:16 pm
 * Author: bytesmallgames (support@bytesmallgames.com)
 * 
 * Copyright (c) 2018 - 2019 Bytesmallgames
 */

#include "my.h"

int score_screen (sfRenderWindow *window, sfEvent event, t_game *element)
{
    char str[100];
    sfVector2f position;
    sfText* score = create_texte("0", "font/ARCADE.otf", 50);
    sfText* depth;
    sfText* level;

    sprintf(str, "%d", element->score);
    score = create_texte(str, "font/ARCADE.otf", 50);
    sfText_setPosition(score, position);
    sfText_setColor(score, sfWhite);
    sprintf(str, "%d", element->depth);
    depth = create_texte("0", "font/ARCADE.otf", 50);
    sfText_setPosition(depth, position);
    sfText_setColor(depth, sfWhite);
    sprintf(str, "%d", element->level);
    level = create_texte("0", "font/ARCADE.otf", 50);
    sfText_setPosition(level, position);
    sfText_setColor(level, sfWhite);
    while (sfRenderWindow_isOpen(window)) {

        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed) {

                gameloop(window, event);
            }
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
	    }
    }
    sfText_destroy(score);
    sfText_destroy(depth);
    sfText_destroy(level);
    sfRenderWindow_destroy(window);
    return (0);
}