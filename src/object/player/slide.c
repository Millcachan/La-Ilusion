/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** slide
*/

#include "core.h"
#include "game.h"
#include "scene.h"
#include "macro.h"
#include "player.h"


void player_slide(player_t *player)
{
    player->pl_state = PL_SLIDE;
    // TODO: change the sprite to sliding animation
}
