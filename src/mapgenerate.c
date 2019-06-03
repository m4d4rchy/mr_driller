/*
 * Filename: initialization.c
 * Project: mr_driller
 * Created Date: Thursday, December 20th 2018, 10:47:47 am
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

sfSprite ***createBlock (int **board) 
{
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
            else if (board[row][col] == 4) {
                area.top = 200;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }
            else if (board[row][col] == 5) {
                area.top = 250;
                blocks[row][col] = my_sprite_rec("img/block.png", area);
            }                                    
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

int **genBlock(void)
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
    genAir();
    return (board);
}

int **genAir(int **board)
{
    int row = 0;
    while (board[row] != NULL) {
        if ((rand() % 5) == 3) {
            board[row][rand() % 6] = 5;
        }
        row = row + 1;
    }
    return (board);
}

int **genBox(int **board)
{
    int row = 0;
    while (board[row] != NULL) {
        if ((rand() % 2) == 2) {
            board[row][rand() % 6] = 4;
        }
        row = row + 1;
    }
    return (board);
}