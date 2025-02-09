/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display_menu.c
*/

#include "game.h"
#include "macro.h"
#include "object/player.h"


void display_death(game_t *game)
{
    if (!game)
        return;

    scene_death_t *data = game->scene->data;

    for (int i = 0; data->background[i]; i++)
        SPRITE_DRAW(game->screen.window, data->background[i], NULL);
    TEXT_DRAW(game->screen.window, data->text_death, NULL);
    TEXT_DRAW(game->screen.window, data->text_score, NULL);
    RECTANGLE_DRAW(game->screen.window, data->fade, NULL);
}
