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


platform_t *platform_create(unsigned char color, sfTexture **textures)
{
    if (color > 1) {
        fprintf(stderr, "Error: color %hhu is not a valid color", color);
        exit(ERROR);
    }

    platform_t *platform = malloc(sizeof(platform_t));

    platform->color = color;
        if (platform->color)
        platform->is_active = false;
    else
        platform->is_active = true;
    platform->sprite = sfSprite_create();

    sfSprite_setTexture(platform->sprite, textures[color], sfFalse);
    platform_randomize_width(platform);

    return platform;
}
