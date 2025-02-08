/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** jump
*/

#include "core.h"
#include "game.h"
#include "scene.h"
#include "macro.h"
#include "player.h"


void player_jump(player_t *player)
{
    player->accel_y += JUMP_STRENGTH;
    player->pl_state = PL_JUMP;
}
