/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** update.c
*/

#include "struct.h"
#include "scene.h"
#include "macro.h"
#include "core.h"

void change_music(game_t *game, int index)
{
    sfMusic_stop(game->current.music);
    game->current.music = game->musics.music[index];
    sfMusic_setVolume(game->current.music, game->musics.volume[index]);
    sfMusic_setLoop(game->current.music, sfTrue);
    sfMusic_play(game->current.music);
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

    for (int i = 0; scenes[i].scene != NONE; i++) {
        if (scenes[i].scene == game->scene) {
            scenes[i].update(game);
            break;
        }
    }

    update_music(game);
}