/*
 * Filename: main_menu.c
 * Project: mr_driller
 * Created Date: Saturday, May 25th 2019, 6:01:47 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#include "my.h"

int splashscreen (sfRenderWindow *window, sfEvent event) 
{
    t_logo element = logo_display_init();
    float seconds;

    while (sfRenderWindow_isOpen(window)) {
        element.fade =  sfClock_getElapsedTime(element.clock);
        seconds = element.fade.microseconds / 250000.0;
        sfRenderWindow_clear(window, sfBlack);
        if (seconds > 0.15 && element.color.a < 255) {
            element.color.a = element.color.a + 5;
            sfClock_restart(element.clock);
        }
        sfSprite_setColor(element.logo, element.color); 	
        sfRenderWindow_drawSprite(window, element.logo, NULL);
        sfRenderWindow_display(window);
        if (element.color.a == 255) {
            sfClock_destroy(element.clock); 	
            sfSprite_destroy(element.logo);
            main_menu(window, event);
        }
    }
    return (0);
}