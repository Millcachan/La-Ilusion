/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_replace
*/

#include "object/platform.h"
#include "macro.h"
#include <stdlib.h>


// TODO: change this (code duplication)
static int generate_width(void)
{
    return
        rand() % (PLATFORM_MAX_WIDTH - PLATFORM_MIN_WIDTH) +
        PLATFORM_MIN_WIDTH;
}


void platform_replace(platform_t *platform, sfTexture **textures)
{
    unsigned char new_color = (unsigned char)(rand() % 2);

    if (new_color != platform->color) {
        sfSprite_setTexture(platform->sprite, textures[new_color], sfFalse);
        platform->color = new_color;
        platform->is_active = !platform->is_active;
    }

    sfSprite_setTextureRect(platform->sprite, (sfIntRect){
        0, 0, generate_width(), 13
    });

    // TODO: replace this
    sfSprite_setPosition(platform->sprite, (sfVector2f){
        711.f, (float)WINDOW_HEIGHT / 2 + 32.f
    });
}
