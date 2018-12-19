/*
 * Filename: game.c
 * Project: mr_driller
 * Created Date: Monday, December 17th 2018, 5:27:50 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2018 Yassine Benmessahel
 */

#include "my.h"

int gameloop (sfRenderWindow *window, sfEvent event) 
{
    int **board = my_createboard();
    sfSprite ***blocks = initialize_game(board);
    sfSprite *gamegui = my_sprite("img/gamegui.png");
    sfSprite *gameback = my_sprite("img/gameback.jpg");
    sfVector2f position;
    position.x = 350;
    position.y = 0;
    int count = 0;

    printf("first %d\n", board[0][0]);
    sfSprite_setPosition(gamegui, position);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
	    }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, gameback, NULL);
        sfRenderWindow_drawSprite(window, gamegui, NULL);
        while (count != 7) {
            sfRenderWindow_drawSprite(window, blocks[0][count], NULL);
            count = count + 1;
        }
        count = 0;
        sfRenderWindow_display(window);
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

    while (row != 1) {
        blocks[row] = malloc(sizeof(*blocks) * 7);
        while (col != 7) {
            if (board[row][col] == 0)
                blocks[row][col] = my_sprite_rec("img/block.png", area);
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
            else
                blocks[row][col] = my_sprite_rec("img/block.png", area);
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
        col = 0;
        row = row + 1;
    }
    return (blocks);
}

int **my_createboard()
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
            board[row] = malloc(sizeof (int) * 46); 
        while (col != 45) {
            if (col == 45)
                board[row][col] = -1;
            else {
                board[row][col] = (rand() % 6);
            }
            printf("%d\n", board[row][col]);
            col = col + 1;
        }
        col = 0;
        row = row + 1;
    }
    return (board);
}

int start_menu (sfRenderWindow *window, sfEvent event)
{
    sfSprite *background = my_sprite("img/menubg.jpg");
    sfFont *font = sfFont_createFromFile("font/retro.ttf");
    sfText *message = sfText_create();
    sfClock *clock = sfClock_create();
    sfTime fade;
    float seconds;
    sfVector2f position;
    position.x = 115;
    position.y = 500;
    int show = 0;

    sfText_setPosition(message, position);
    sfText_setFont(message, font);
    sfText_setString(message, "PRESS ANY KEY TO START");
    while (sfRenderWindow_isOpen(window)) {
        fade =  sfClock_getElapsedTime(clock);
        seconds =  fade.microseconds / 250000.0;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        if (seconds > 1.5) {
            if (show == 0)
                show = 1;
            else 
                show = 0;
            sfClock_restart(clock);
        }
        if (show == 1)
            sfRenderWindow_drawText(window, message, NULL);
        
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed) {
                sfSprite_destroy(background);
                sfText_destroy(message);
                gameloop(window, event);
            }
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
	    }
    }
    return (0);
}

int logo_display (sfRenderWindow *window, sfEvent event) 
{
    sfClock *clock = sfClock_create();
    sfTime fade;
    sfColor color;
    float seconds;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 0;
    sfSprite *logo = my_sprite("img/Namco-Logo.jpg");
    while (sfRenderWindow_isOpen(window)) {
        fade =  sfClock_getElapsedTime(clock);
        seconds =  fade.microseconds / 250000.0;
        sfRenderWindow_clear(window, sfBlack);
        if (seconds > 0.15 && color.a < 255) {
            color.a = color.a + 5;
            sfClock_restart(clock);
        }
        sfSprite_setColor(logo, color); 	
        sfRenderWindow_drawSprite(window, logo, NULL);
        sfRenderWindow_display(window);
        if (color.a == 255) {
            sfClock_destroy(clock); 	
            sfSprite_destroy(logo);
            start_menu(window, event);
        }
    }
    return (0);
}