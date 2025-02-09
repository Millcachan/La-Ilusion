/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for
** update_ingame
*/

#include "game.h"
#include "object/player.h"
#include "macro.h"


void update_ingame(game_t *game)
{
    if (!game)
        return;

    scene_ingame_t *data = game->scene->data;

    for (int i = 0; data->background[i]; i++) {
        sfIntRect rect = sfSprite_getTextureRect(data->background[i]);
        rect.left += (int)(game->speed) * (i * 2);
        sfSprite_setTextureRect(data->background[i], rect);
    }
    player_update(data->player, data->player_textures);

    char time_str[16];
    data->time += 1.0f / 144.0f;
    snprintf(time_str, sizeof(time_str), "SCORE : %d", (int)(data->time * 100));
    sfText_setString(data->timer_text, time_str);
}
