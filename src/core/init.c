/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** init.c
*/

#include "core.h"
#include "scene.h"
#include "game.h"
#include "macro.h"
#include "sound.h"
#include "assets.h"

/**
 * @brief Init the screen and windows options.
 */
static void init_screen(screen_t *screen)
{
    screen->mode = (sfVideoMode){800, 600, 32};
    screen->window = WINDOW_CREATE(screen->mode, "La Ilusion", sfClose, NULL);
    WINDOW_FRAMELIMIT(screen->window, 144);
}

static musics_t init_musics(void)
{
    musics_t musics = { 0 };

    return musics;
}

/**
 * @brief Initialize the main structure of the game.
 */
game_t *init_game(game_t *game)
{
    init_screen(&game->screen);
    game->clock = CLOCK_CREATE();
    game->musics = init_musics();
    game->current_music = game->musics.music[0];
    change_scene(game, ST_NONE);
    // sfMusic_setVolume(game->current.music, 80.0f);
    // sfMusic_setLoop(game->current.music, sfTrue);
    // sfMusic_play(game->current.music);
    return game;
}
