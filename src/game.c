/*
 * Filename: game.c
 * Project: mr_driller
 * Created Date: Monday, December 17th 2018, 5:27:50 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#include "my.h"

int gameloop (sfRenderWindow *window, sfEvent event) 
{
    int **board = createboard();
    t_game element = gameloop_init();
    element.blocks = initialize_game(board);

    sfMusic_play(element.music);
    element.clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        element.time =  sfClock_getElapsedTime(element.clock);
        element.seconds = element.time.microseconds / 250000.0;
        if (element.seconds > 2) {
            element.air = element.air - 1;
            sfClock_restart(element.clock);
        }

        // Start Display Section
        sfRenderWindow_drawSprite(window, element.background, NULL);
        sfRenderWindow_drawSprite(window, element.gamegui, NULL);
        for (int i = 0; i != 4; i++) {
            sfRenderWindow_drawText(window, element.text[i], NULL);
        }
        sfRenderWindow_drawSprite(window, element.player, NULL);
        for (int row = 0; row != 8; row++) {
            for (int col = 0; col != 7; col++)
                sfRenderWindow_drawSprite(window, element.blocks[row][col], NULL);
        }
        //print_gamegui(&element);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        // End Display Section
        
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfMusic_stop(element.music);
                sfMusic_destroy(element.music);
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed) {
                //player_movement(event);

            }
	    }
    }
    return (0);
}