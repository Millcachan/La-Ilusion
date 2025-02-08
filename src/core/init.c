/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** init.c
*/

#include "core.h"
#include "struct.h"
#include "macro.h"
#include "sound.h"

/**
 * @brief Init the screen and windows options.
 */
static void init_screen(screen_t *screen)
{
    screen->mode = (sfVideoMode){800, 600, 32};
    screen->window = WINDOW_CREATE(screen->mode, "Window Name", sfClose, NULL);
    WINDOW_FRAMELIMIT(screen->window, 144);
}

static musics_t init_musics(void)
{
    musics_t musics;

    return musics;
}

static player_t init_player(void)
{
    player_t player;

    player.pl_sprite = sfSprite_create()
    sfSprite
}

/**
 * @brief Initialize the main structure of the game.
 */
game_t *init_game(game_t *game)
{
    init_screen(&game->screen);
    game->clock = CLOCK_CREATE();
    game->musics = init_musics();
    game->current.music = game->musics.music[0];
    change_scene(game, NONE);
    // sfMusic_setVolume(game->current.music, 80.0f);
    // sfMusic_setLoop(game->current.music, sfTrue);
    // sfMusic_play(game->current.music);
    return game;
}