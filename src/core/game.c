/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** game.c
*/

#include "core.h"
#include "usage.h"
#include "macro.h"
#include <unistd.h>

/**
 * @brief Call to get the main struct from everywhere in the program.
 */
game_t *get_game(void)
{
    static game_t *game = NULL;

    if (!game) {
        game = malloc((size_t)sizeof(game_t));
    }
    return game;
}

float get_time(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);

    return (float)((double)time.microseconds / 1000000.0);
}

/**
 * @brief The main loop of the game.
 */
int game(void)
{
    game_t *game = init_game(get_game());
    float seconds;

    while (IS_OPEN(game->screen.window)) {
        seconds = get_time(game);
        while (POLL_EVENT(game->screen.window, &game->screen.event)) {
            event_manager(game);
        }
        if (seconds > 0.1) {
            update(game);
        }
        display(game);
    }
    free_game(game);
    return SUCCESS;
}