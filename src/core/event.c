/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** event.c
*/

#include "core.h"
#include "struct.h"
#include "scene.h"
#include "macro.h"

/**
 * @brief Manage every event related to the current scene.
 */
void event_manager(game_t *game)
{
    if (game->screen.event.type == sfEvtClosed) {
        CLOSE(game->screen.window);
    }

    for (int i = 0; scenes[i].scene != NONE; i++) {
        if (scenes[i].scene == game->scene) {
            scenes[i].event_manager(game);
            break;
        }
    }
}
