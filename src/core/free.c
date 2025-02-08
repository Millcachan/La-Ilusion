/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** free.c
*/

#include "struct.h"
#include "macro.h"
#include <stdlib.h>

/**
 * @brief Free the current loaded scene.
 */
void free_current_scene(cur_scene_t *current, game_t *game)
{
    sfMusic_destroy(current->music);
}

static void free_music(game_t *game)
{
    for (int i = 0; i < 1; i++) {
        sfMusic_destroy(game->musics.music[i]);
    }
}

/**
 * @brief Free the main structure and every sub structures.
 */
void free_game(game_t *game)
{
    CLOCK_DESTROY(game->clock);
    WINDOW_DESTROY(game->screen.window);
    free_music(game);
    free(game);
}