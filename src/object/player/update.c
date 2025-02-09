/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for player
** update function
*/

#include "object/player.h"
#include "macro.h"
#include <SFML/Graphics.h>
#include <stdbool.h>


/**
 * @brief Player's update function. This
 * function relies on being called a fixed
 * amount of times
 */
void player_update(player_t *player, sfTexture **textures)
{
    sfVector2f position = sfSprite_getPosition(player->sprite);

    // Update the player's acceleration
    if (player->state != PS_JUMP && sfKeyboard_isKeyPressed(sfKeySpace))
        player_jump(player, textures);

    // Handle sliding
    bool slide_key_pressed = sfKeyboard_isKeyPressed(sfKeyC);

    if (player->state == PS_NORMAL && slide_key_pressed)
        player_slide(player, textures);
    if (player->state == PS_SLIDE && !slide_key_pressed)
        player_run(player, textures);

    // Apply the player's acceleration
    position.y -= player->accel_y;

    // Apply gravity if in the air
    if (player->state == PS_JUMP)
        player->accel_y -= PLAYER_GRAVITY;

    // Update the player's position
    sfSprite_setPosition(player->sprite, position);

    player->state = PS_JUMP;
}
