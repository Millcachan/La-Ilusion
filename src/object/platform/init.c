/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_create
*/

#include "object/platform.h"
#include <stdlib.h>


/**
 * @brief Generate all platforms and
 * insert them into the given platforms
 * array.
 */
void platforms_init(platform_t **platforms, sfTexture **textures)
{
    unsigned char current_color = PC_RED;

    for (int i = 0; i < 20; i++) {
        sfVector2f platform_position =
            platform_generate_position(i == 0 ? NULL : platforms[i - 1]);

        platforms[i] = platform_create(current_color, textures);
        if (i == 0)  // Make the first platform bigger (easier for player)
            sfSprite_setTextureRect(platforms[0]->sprite, (sfIntRect){ 0, 0, 200, 13 });
        sfSprite_setPosition(platforms[i]->sprite, platform_position);

        current_color = (unsigned char)(current_color + 1) % 2;  // go to next color
    }

}
