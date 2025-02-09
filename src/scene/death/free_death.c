/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for
** free_ingame
*/

#include "game.h"


void free_death(game_t *game)
{
    if (!game)
        return;

    scene_death_t *data = game->scene->data;
    if (!data)
        return;
    
    for (int i = 0; data->background[i]; i++) {
        sfTexture_destroy(data->background_texture[i]);
        sfSprite_destroy(data->background[i]);
    }
    sfRectangleShape_destroy(data->fade);
    free(data->background);
    free(data->background_texture);
    free(data);
    free(game->scene);
}
