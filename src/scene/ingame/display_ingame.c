/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display_menu.c
*/

#include "game.h"
#include "macro.h"

void display_ingame(game_t *game)
{
    if (!game)
        return;

    scene_ingame_t *data = game->scene->data;

    for (int i = 0; data->background[i]; i++) {
        SPRITE_DRAW(game->screen.window, data->background[i], NULL);
        SPRITE_DRAW(game->screen.window, data->player->sprite, NULL);
    }

}
