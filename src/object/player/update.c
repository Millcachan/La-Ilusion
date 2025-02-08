/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for player
** update function
*/

#include "player.h"


void player_update(player_t *player)
{
    sfVector2f position = sfSprite_getPosition(player->pl_sprite);

    // Reset the player's state to normal if sliding
    if (player->pl_state == PL_SLIDE)
        player->pl_state = PL_NORMAL;

    // Update the player's acceleration
    if (player->pl_state != PL_JUMP && sfKeyboard_isKeyPressed(sfKeySpace))
        player_jump(player);

    // Handle sliding
    if (player->pl_state == PL_NORMAL && sfKeyboard_isKeyPressed(sfKeyC))
        player_slide(player);

    // Update the player's position
    position.y -= player->accel_y;

    // Apply gravity if in the air
    if (player->pl_state == PL_JUMP)
        player->accel_y -= PLAYER_GRAVITY;

    sfSprite_setPosition(player->pl_sprite, position);
}