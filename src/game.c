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
    char strint[100];
    int **board = createboard();
    t_game element = gameloop_init();
    element.blocks = initialize_game(board);

    sfMusic_play(element.music);
    while (sfRenderWindow_isOpen(window)) {
        element.time =  sfClock_getElapsedTime(element.clock);
        element.seconds = element.time.microseconds / 250000.0;
        if (element.seconds > 2) {
            element.air = element.air - 1;
            sprintf(strint, "%d%%", element.air);
            sfText_setString(element.text[2], strint);
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

sfSprite ***initialize_game (int **board) 
{
    (void)board;
    int row = 0;
    int col = 0;
    sfIntRect area;
    area.left = 0;
    area.top = 0;
    area.width = 50;
    area.height = 50;
    sfSprite ***blocks = malloc(sizeof(**blocks) * 7);
    sfVector2f position;
    position.x = 0;
    position.y = 200;

    while (row != 8) {
        blocks[row] = malloc(sizeof(*blocks) * 7);
        while (col != 7) {
            if (board[row][col] == 0) {
                area.top = 0;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }
            else if (board[row][col] == 1) {
                area.top = 50;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }
            else if (board[row][col] == 2) {
                area.top = 100;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }
            else if (board[row][col] == 3) {
                area.top = 150;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }
            /*else
                blocks[row][col] = my_sprite_rec("img/block.png", area);*/
            /*else if (board[row][col] == 4) {
                area.top = 200;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }
            else if (board[row][col] == 5) {
                area.top = 250;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }*/                                    
            sfSprite_setPosition(blocks[row][col], position);
            position.x = position.x + 50;
            col = col + 1;
        }
        position.x = 0;
        position.y = position.y + 50;
        col = 0;
        row = row + 1;
    }
    return (blocks);
}

int **createboard(void)
{
    int **board = malloc(sizeof (int *) * 501);
    int row = 0;
    int col = 0;
    time_t t;

    srand(time(&t));
    while (row != 500) {
        if (row == 500)
            board[row] = NULL;
        else
            board[row] = malloc(sizeof (int) * 8); 
        while (col != 7) {
            if (col == 7)
                board[row][col] = -1;
            else {
                board[row][col] = (rand() % 4);
            }
            printf("%d", board[row][col]);
            col = col + 1;
        }
        printf("\n");
        col = 0;
        row = row + 1;
    }
    return (board);
}