/*
 * Filename: game.c
 * Project: mr_driller
 * Created Date: Monday, December 17th 2018, 5:27:50 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2019 Yassine Benmessahel
 */

#include "my.h"

int print_gameui(t_game *element)
{
    char str[100];

    sprintf(str, "%d", element->depth);
    sfText_setString(element->text[0], str);
    sprintf(str, "%d", element->score);
    sfText_setString(element->text[1], str);
    sprintf(str, "%d%%", element->air);
    sfText_setString(element->text[2], str);
    sprintf(str, "%d", element->level);
    sfText_setString(element->text[3], str);
    return (0);
}