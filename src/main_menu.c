/*
 * Filename: main_menu.c
 * Project: mr_driller
 * Created Date: Thursday, December 20th 2018, 3:53:38 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#include "my.h"

int main_menu (sfRenderWindow *window, sfEvent event)
{
    t_startmenu element = main_menu_init();
    sfMusic_play(element.music);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, element.background, NULL);
        circle_animation(window, &element);
        sfRenderWindow_drawSprite(window, element.image, NULL);
        logo_drop(window, &element);
        blink_effect(window, &element);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed) {
                sfMusic_stop(element.music);
                sfMusic_play(element.sfx);
                sfMusic_destroy(element.music);
                sfSprite_destroy(element.background);
                sfSprite_destroy(element.logo);
                sfSprite_destroy(element.image);
                sfText_destroy(element.message);
                gameloop(window, event);
                sfMusic_destroy(element.sfx);
            }
            if (event.type == sfEvtClosed) {
                sfMusic_stop(element.music);
                sfMusic_destroy(element.music);
                sfMusic_destroy(element.sfx);
                sfSprite_destroy(element.background);
                sfSprite_destroy(element.logo);
                sfSprite_destroy(element.image);
                sfText_destroy(element.message);
                sfRenderWindow_close(window);
            }
	    }
    }
    return (0);
}

int blink_effect (sfRenderWindow *window, t_startmenu *element)
{
    static float seconds;
    static int show = 0;

    element->message_time =  sfClock_getElapsedTime(element->message_clock);
    seconds =  element->message_time.microseconds / 250000.0;
    if (seconds > 1.5) {
            if (show == 0)
                show = 1;
            else 
                show = 0;
            sfClock_restart(element->message_clock);
        }
    if (show == 1)
        sfRenderWindow_drawText(window, element->message, NULL);

    return (0);
}

int circle_animation (sfRenderWindow *window, t_startmenu *element) 
{
    static float seconds;

    element->circle_time =  sfClock_getElapsedTime(element->circle_clock);
    seconds =  element->circle_time.microseconds / 250000.0;

    if (seconds > 0.05) {
        if (element->circle_area1.top == 200) {
            element->circle_area1.top = 0;
            element->circle_area2.top = 50;
            element->circle_area3.top = 100;
            sfSprite_setTextureRect(element->circle[0], element->circle_area1);
            sfSprite_setTextureRect(element->circle[1], element->circle_area2);
            sfSprite_setTextureRect(element->circle[2], element->circle_area3);

        }
        if (element->circle_position[0].x == -50) {
            element->circle_position[0].x = 650;
            element->circle_position[1].x = -50;
            element->circle_position[2].x = 650;
            element->circle_area1.top = element->circle_area1.top + 50;
            element->circle_area2.top = element->circle_area2.top + 50;
            element->circle_area3.top = element->circle_area3.top + 50;
            sfSprite_setTextureRect(element->circle[0], element->circle_area1);
            sfSprite_setTextureRect(element->circle[1], element->circle_area2);
            sfSprite_setTextureRect(element->circle[2], element->circle_area3);

        }
        element->circle_position[0].x = element->circle_position[0].x - 2;
        element->circle_position[1].x = element->circle_position[1].x + 2;
        element->circle_position[2].x = element->circle_position[2].x - 2;
        sfSprite_setPosition(element->circle[0], element->circle_position[0]);
        sfSprite_setPosition(element->circle[1], element->circle_position[1]);
        sfSprite_setPosition(element->circle[2], element->circle_position[2]);
        sfClock_restart(element->circle_clock);
    }
    sfRenderWindow_drawSprite(window, element->circle[0], NULL);
    sfRenderWindow_drawSprite(window, element->circle[1], NULL);
    sfRenderWindow_drawSprite(window, element->circle[2], NULL);
    return (0);
}

int logo_drop (sfRenderWindow *window, t_startmenu *element)
{
    static float seconds;

    if (element->logo_position.y < 0) {
        element->logo_time =  sfClock_getElapsedTime(element->logo_clock);
        seconds =  element->message_time.microseconds / 250000.0;
        if (seconds > 0.5)
            element->logo_position.y = element->logo_position.y + 1;
        sfSprite_setPosition(element->logo, element->logo_position);
        sfClock_restart(element->logo_clock);
    }
    sfRenderWindow_drawSprite(window, element->logo, NULL);
    return (0);
}