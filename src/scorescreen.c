/*
 * Filename: scorescreen.c
 * Project: mr_driller
 * Created Date: Saturday, May 25th 2019, 8:39:16 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#include "my.h"

int score_screen (sfRenderWindow *window, sfEvent event)
{
    t_startmenu element = main_menu_init();
    sfMusic_play(element.music);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed) {
            }
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
	    }
    }
    return (0);
}