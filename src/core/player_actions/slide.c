/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** slide
*/

#include "core.h"
#include "struct.h"
#include "scene.h"
#include "macro.h"
#include "player.h"


void check_slide(game_t *game)
{
    // faire slide le joueur s'il est au sol (avoid slide while jumping);
    if (sfKeyboard_isKeyPressed(sfKeyD) && game->player->pl_state == PL_NORMAL) {
        game->player->pl_state = PL_SLIDE;
        game->player->scale.y /= 2;
        sfRectangleShape_setScale(game->player->pl_sprite, game->player->scale);
        sfintrec
    // si le joueur n'appuie plus sur la touche de slide, remettre l'état normal
    } else if (game->player->pl_state == PL_SLIDE) {
        game->player->scale.y *= 2;
        sfRectangleShape_setScale(game->player->pl_sprite, game->player->scale);
        game->player->pl_state = PL_NORMAL;
        }
}

// todo: changer les sprites pendant le slide pour l'animation
