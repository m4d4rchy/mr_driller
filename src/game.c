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
    t_game element = gameloop_init();
    element.board = genBlock();
    element.blocks = createBlock(element.board);

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
        for (int row = 0; row != 500; row++) {
            for (int col = 0; col != 7; col++) {
                if (element.board[row][col] != 0)
                    sfRenderWindow_drawSprite(window, element.blocks[row][col], NULL);
            }
        }
        print_gameui(&element);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        // End Display Section
        
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyReleased) {
                printf("key pressed\n");
                player_movement(&element, event.key.code);
            }
            if (event.type == sfEvtClosed) {
                sfMusic_stop(element.music);
                //sfMusic_destroy(element.music);
                sfRenderWindow_close(window);
            }
	    }
    }
    return (0);
}

int player_movement(t_game *element, sfKeyCode code)
{
    //static int right;
    //static int left;
    if (code == sfKeyRight && element->player_position.x < 307) {
        /*if (right == 1) {
            printf("drill right\n");
        }*/
        printf("right\n");
        element->player_position.x = element->player_position.x + 50;
        sfSprite_setPosition(element->player, element->player_position);
        element->player_block_pos[1] = element->player_block_pos[1] + 1;
        //right = 1;
    }
    if (code == sfKeyLeft && element->player_position.x > 7) {
        /*if (left == 1) {
            printf("drill left\n");
        }*/
        printf("left\n");
        element->player_position.x = element->player_position.x - 50;
        sfSprite_setPosition(element->player, element->player_position);
        element->player_block_pos[1] = element->player_block_pos[1] - 1;
        //left = 1;
    }
    if (code == sfKeyDown) {
        drillBlock("down" ,element);
        //right = 0;
        //left = 0;
    }
    printf("pos x: %f\n", element->player_position.x);
    return (0);
}

int drillBlock(const char *direction, t_game *element)
{
    int drill = element->board[element->player_block_pos[0]][element->player_block_pos[1]];
    int row = element->player_block_pos[0];
    int col = element->player_block_pos[1] + 1;

    if (strcmp(direction, "down") == 0) {
        while (element->board[row][col] == drill) {
            element->board[row][col] = 0;
            sfSprite_destroy(element->blocks[row][col]);
            element->score = element->score + 1;
            col = col + 1;
        }
        row = element->player_block_pos[0];
        col = element->player_block_pos[1] - 1;
        while (element->board[row][col] == drill && col > -1) {
            element->board[row][col] = 0;
            sfSprite_destroy(element->blocks[row][col]);
            element->score = element->score + 1;
            col = col - 1;
        }
        row = element->player_block_pos[0];
        col = element->player_block_pos[1];
        while (element->board[row][col] == drill) {
            element->board[row][col] = 0;
            sfSprite_destroy(element->blocks[row][col]);
            moveBoard(element);
            element->player_block_pos[0] = element->player_block_pos[0] + 1;
            element->depth = element->depth + 1;
            element->score = element->score + 1;
            row = row + 1;
        }
    }
    return (0);
}

void moveBoard(t_game *element)
{
    sfVector2f offset;
    offset.x = 0;
    offset.y = -2;
    sfSprite_move(element->background, offset);
    offset.y = -50;
    for (int row = 0; row != 8; row++) {
            for (int col = 0; col != 7; col++) {
                if (element->board[row][col] != 0)
                    sfSprite_move(element->blocks[row][col], offset);
            }
        }
}