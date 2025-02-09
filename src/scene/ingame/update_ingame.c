/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Implementation for
** update_ingame
*/

#include "game.h"
#include "object/platform.h"
#include "object/player.h"


void update_ingame(game_t *game)
{
    if (!game)
        return;

    scene_ingame_t *data = game->scene->data;

    // Update background:
    for (int i = 0; data->background[i]; i++) {
        sfIntRect rect = sfSprite_getTextureRect(data->background[i]);
        rect.left += (int)(game->speed) * (i * 2);
        sfSprite_setTextureRect(data->background[i], rect);
    }

    // Update player:
    player_state_t player_state = data->player->state;
    player_update(data->player, data->player_textures);

    // Update platforms:
    for (int i = 0; i < 20; i++)
        platform_update(data->platforms[i], data);

    // Update player state (influenced by platforms during collisions):
    if (data->player->state != player_state)
        player_update_texture(data->player, data->player_textures);
}
