/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** update.c
*/

#include "game.h"
#include "scene.h"
#include "macro.h"
#include "core.h"

void change_music(game_t *game, int index)
{
    sfMusic_stop(game->current_music);
    game->current_music = game->musics.music[index];
    sfMusic_setVolume(game->current_music, game->musics.volume[index]);
    sfMusic_setLoop(game->current_music, sfTrue);
    sfMusic_play(game->current_music);
}

static void update_music(game_t *game)
{

}

/**
 * @brief Update every entity related to the current scene.
 */
void update(game_t *game)
{
    CLOCK_RESTART(game->clock);

    if (game->scene_type == ST_NONE)
        return;

    scenes[game->scene_type].update(game);
    update_music(game);
}
