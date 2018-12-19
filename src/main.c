/*
 * Filename: main.c
 * Project: mr_driller
 * Created Date: Monday, December 17th 2018, 1:47:44 pm
 * Author: yassine.b (yassine.b@caramail.com)
 * 
 * Copyright (c) 2018 - 2018 Yassine Benmessahel
 */

#include "my.h"

int main (int argc, char **argv, char *env[])
{
    (void)argc;
	(void)argv;
    sfRenderWindow *window;
    sfEvent event;

    if (env[0] == NULL)
		return (84);
	window = create_window("Mr. Driller", 600, 600);
    logo_display(window, event);
    return (0);
}

sfRenderWindow *create_window(char *name, int width, int height)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
	return (window);
}

sfSprite *my_sprite(const char *filename)
{
	sfTexture *texture;
	sfSprite *sprite;

	sprite = sfSprite_create();
	texture = sfTexture_createFromFile(filename, NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	return (sprite);
}

sfSprite *my_sprite_rec(const char *filename, sfIntRect area)
{
	(void)area;
	sfTexture *texture;
	sfSprite *sprite;

	sprite = sfSprite_create();
	texture = sfTexture_createFromFile(filename, NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, area);
	return (sprite);
}


