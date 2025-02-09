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
#include <math.h>


static float generate_offset(void)
{
    return (float)(rand() % 100) + 40.f;
}

static void multiply_vector(sfVector2f *vector, float mult)
{
    vector->x *= mult;
    vector->y *= mult;
}

static void normalize_vector(sfVector2f *vector)
{
    float magnitude = sqrtf(vector->x * vector->x + vector->y * vector->y);

    vector->x /= magnitude;
    vector->y /= magnitude;
}

sfVector2f platform_generate_position(const platform_t *previous)
{
    if (previous == NULL)
        return (sfVector2f){ 0.0f, (float)WINDOW_HEIGHT / 2 + 34.f };

    sfVector2f position = sfSprite_getPosition(previous->sprite);
    sfVector2f random_direction = {
        (float)(rand() % 990) + 10,
        (float)(rand() % 750) - 375,  // allow less variation in y axis
    };

    normalize_vector(&random_direction);
    multiply_vector(&random_direction, generate_offset());

    float previous_width = sfSprite_getGlobalBounds(previous->sprite).width;
    position.x += random_direction.x + previous_width;
    position.y += random_direction.y;

    // Clamp y so it doesn't go out of screen
    if (position.y + 40.f <= 0.f)
        position.y += 80.f;
    if (position.y + 13.f >= WINDOW_HEIGHT)
        position.y -= 80.f;

    return position;
}
