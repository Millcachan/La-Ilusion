/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** unload_sprite
*/

#include "assets.h"


/**
 * @brief Fully unloads the given sprite
 * and its texture.
 */
void unload_sprite(sfSprite *sprite)
{
    // It is safe to remove const-qualifier since texture is not shared
    sfTexture *texture = (sfTexture *)sfSprite_getTexture(sprite);

    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
