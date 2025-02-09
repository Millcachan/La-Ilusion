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


static int generate_x_offset(void)
{
    return
        rand() % 100 +
        20;
}

sfVector2f platform_generate_position(const platform_t *previous)
{
    if (previous == NULL)
        return (sfVector2f){ 0.0f, (float)WINDOW_HEIGHT / 2 + 32.f };

    sfVector2f position = sfSprite_getPosition(previous->sprite);

    float prev_width = sfSprite_getGlobalBounds(previous->sprite).width;

    position.x += prev_width;  // prevent collisions
    position.x += (float)generate_x_offset();
    position.y += (float)(rand() % 80 - 40);

    return position;
}
