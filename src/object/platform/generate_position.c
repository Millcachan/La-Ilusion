/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_generate_position
*/

#include "object/platform.h"
#include "macro.h"
#include <stdlib.h>


static float generate_x_offset(void)
{
    return (float)(rand() % 80) + 40.f;
}

sfVector2f platform_generate_position(const platform_t *previous)
{
    if (previous == NULL)
        return (sfVector2f){ 0.0f, (float)WINDOW_HEIGHT / 2 + 34.f };

    sfVector2f position = sfSprite_getPosition(previous->sprite);

    float prev_width = sfSprite_getGlobalBounds(previous->sprite).width;

    position.x += prev_width + generate_x_offset();
    position.y += (float)(rand() % 80 - 40);

    return position;
}
