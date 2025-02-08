/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** jump
*/

#include "object/player.h"


void player_jump(player_t *player)
{
    player->accel_y += JUMP_STRENGTH;
    player->state = PS_JUMP;
}
