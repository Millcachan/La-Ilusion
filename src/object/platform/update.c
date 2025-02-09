/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** platform_update
*/

#include "object/platform.h"
#include "object/player.h"
#include "scene.h"
#include "macro.h"
#include <SFML/Graphics/Sprite.h>
#include <stdbool.h>
#include <math.h>


static bool player_collides(sfFloatRect platform_bounds, player_t *player)
{
    sfFloatRect player_bounds = sfSprite_getGlobalBounds(player->sprite);

    // Enlarge player to be able to know where the player is coming from
    float momentum = fabsf(player->accel_y);
    player_bounds.top -= momentum + 1.f;  // + 1 for float imprecision
    player_bounds.height += 2 * (momentum + 1.f);

    return sfFloatRect_intersects(&platform_bounds, &player_bounds, NULL);
}

/**
 * @brief Platform's update function
 */
void platform_update(platform_t *platform, scene_ingame_t *data)
{
    player_t *player = data->player;
    sfVector2f position = sfSprite_getPosition(platform->sprite);
    sfFloatRect platform_bounds = sfSprite_getGlobalBounds(platform->sprite);

    // Delete platform if it goes out of bounds and create a new one
    if (position.x + platform_bounds.width < 0.f) {
        platform_replace(platform, data->platform_textures);
        return;
    }

    // Handle player collision
    if (player_collides(platform_bounds, player))
        handle_collision(platform, player);

    // Update position (give the illusion the player is running)
    position.x -= PLAYER_SPEED;
    sfSprite_setPosition(platform->sprite, position);
}
