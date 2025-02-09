/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_create
*/

#include "object/platform.h"
#include "macro.h"
#include <stdio.h>
#include <stdlib.h>


static int generate_width(void)
{
    return
        rand() % (PLATFORM_MAX_WIDTH - PLATFORM_MIN_WIDTH) +
        PLATFORM_MIN_WIDTH;
}


platform_t *platform_create(unsigned char color, sfTexture **textures)
{
    if (color > 1) {
        fprintf(stderr, "Error: color %hhu is not a valid color", color);
        exit(ERROR);
    }

    platform_t *platform = malloc(sizeof(platform_t));

    platform->color = color;
    platform->is_active = false;  // will be updated in platform_update anyways
    platform->sprite = sfSprite_create();

    sfSprite_setTexture(platform->sprite, textures[color], sfFalse);
    sfSprite_setTextureRect(platform->sprite, (sfIntRect){
        0, 0, generate_width(), 13
    });


    return platform;
}
