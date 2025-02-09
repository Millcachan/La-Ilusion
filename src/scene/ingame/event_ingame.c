/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** event_menu.c
*/

#include "game.h"
#include "core.h"
#include "macro.h"

void event_ingame(game_t *game)
{
    if (!game)
        return;

    scene_ingame_t *data = game->scene->data;

    if (sfKeyboard_isKeyPressed(sfKeyV)) {
        if (data->color)
            data->color = 0;
        else
            data->color = 1;
        printf("%d\n", (int)data->color);
    }
}
