/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** jump
*/

#include "core.h"
#include "struct.h"
#include "scene.h"
#include "macro.h"
#include "player.h"


void check_jump(game_t *game)
{
    // faire sauter le joueur uniquement s'il est au sol (avoid inf jump);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && game->player->pl_state != PL_JUMP) {
        game->player->pl_state = PL_JUMP;
        game->player->position.y -= 250;
        SPRITE_SETPOS(game->player->pl_sprite, game->player->position);
        RECT_POS(game->player->hitbox, game->player->position);
    // si le joueur est dans les airs, augmenter le y pour diminuer sa position (0 étant le haut de l'écran) - peut-être changer la condition par rapport à la clock?
    } else if (game->player->pl_state == PL_JUMP) {
        for (unsigned int i = 0; i < 250; i += 2) {
            game->player->position.y += 2;
            SPRITE_SETPOS(game->player->pl_sprite, game->player->position);
            RECT_POS(game->player->hitbox, game->player->position);
        }
        game->player->pl_state = PL_NORMAL;
    }
}
