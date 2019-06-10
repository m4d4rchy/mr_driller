/*
 * Filename: scorescreen.c
 * Project: mr_driller
 * Created Date: Saturday, May 25th 2019, 8:39:16 pm
 * Author: bytesmallgames (support@bytesmallgames.com)
 * 
 * Copyright (c) 2018 - 2019 Bytesmallgames
 */

#include "my.h"

int scoreScreen (sfRenderWindow *window, sfEvent event, t_game *element)
{
    sfSprite_destroy(element->background);
    element->background = my_sprite("img/menubg.jpg");
    element->gamegui_position.y = 180;
    element->gamegui_position.x = 150;
    sfText_setPosition(element->text[1], element->gamegui_position);
    sfText_setColor(element->text[1], sfWhite);
    element->gamegui_position.y = 230;
    sfText_setPosition(element->text[0], element->gamegui_position);
    sfText_setColor(element->text[0], sfWhite);
    element->gamegui_position.y = 280;
    sfText_setPosition(element->text[3], element->gamegui_position);
    sfText_setColor(element->text[3], sfWhite);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_drawSprite(window, element->background, NULL);
        sfRenderWindow_drawText(window, element->text[1], NULL);
        sfRenderWindow_drawText(window, element->text[0], NULL);
        sfRenderWindow_drawText(window, element->text[3], NULL);
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
    /*sfText_destroy(score);
    sfText_destroy(depth);
    sfText_destroy(level);
    sfRenderWindow_destroy(window);*/
    return (0);
}