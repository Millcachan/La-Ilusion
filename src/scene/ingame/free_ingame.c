/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display_menu.c
*/

#include "game.h"
#include "macro.h"

void free_ingame(game_t *game)
{
    if (!game)
        return;

    scene_ingame_t *data = game->scene->data;
    if (!data)
        return;
    
    for (int i = 0; data->background[i]; i++) {
        sfTexture_destroy(data->background_texture[i]);
        sfSprite_destroy(data->background[i]);
    }
    free(data->background);
    free(data->background_texture);
    free(data);
    free(game->scene);
}