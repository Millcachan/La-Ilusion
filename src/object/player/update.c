/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for player
** update function
*/

#include "object/player.h"
#include <SFML/Graphics.h>


/**
 * @brief Player's update function. This
 * function relies on being called a fixed
 * amount of times
 */
void player_update(player_t *player, sfTexture **textures)
{
    sfVector2f position = sfSprite_getPosition(player->sprite);

    // Reset the player's state to normal if sliding
    if (player->state == PS_SLIDE)
        player->state = PS_NORMAL;

    // Update the player's acceleration
    if (player->state != PS_JUMP && sfKeyboard_isKeyPressed(sfKeySpace))
        player_jump(player, textures);

    // Handle sliding
    if (player->state == PS_NORMAL && sfKeyboard_isKeyPressed(sfKeyC))
        player_slide(player);

    // Apply the player's acceleration
    position.y -= player->accel_y;

    // Apply gravity if in the air
    if (player->state == PS_JUMP)
        player->accel_y -= PLAYER_GRAVITY;

    // Update the player's position
    sfSprite_setPosition(player->sprite, position);

}
