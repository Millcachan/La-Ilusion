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
    musics_t musics;
    const char *files[MUSIC_COUNT] = {
        "../../assets/musics/menu.ogg",
        "../../assets/musics/main_music.ogg",
        "../../assets/musics/start.ogg",
        "../../assets/musics/jump.ogg",
        "../../assets/musics/slide.ogg",
        "../../assets/musics/dead.ogg"
    };
    const float default_volumes[MUSIC_COUNT] = {90.0f, 80.0f, 80.0f, 50.0f, 80.0f, 150.0f};

    for (int i = 0; i < MUSIC_COUNT; i++) {
        musics.music[i] = sfMusic_createFromFile(files[i]);
        musics.volume[i] = default_volumes[i];

        if (!musics.music[i]) {
            fprintf(stderr, "Failed to load music: %s\n", files[i]);
            exit(ERROR);
        }

        sfMusic_setVolume(musics.music[i], musics.volume[i]);
    }
    sfMusic_setLoop(musics.music[MENU], sfTrue);
    sfMusic_setLoop(musics.music[MAIN_MUSIC], sfTrue);

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
