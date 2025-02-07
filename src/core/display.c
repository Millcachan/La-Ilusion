/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** display.c
*/

#include "struct.h"
#include "macro.h"
#include "scene.h"

/**
 * @brief Display every entity related to the current scene.
 */
void display(game_t *game)
{
    CLEAR(game->screen.window, sfBlack);

    for (int i = 0; scenes[i].scene != NONE; i++) {
        if (scenes[i].scene == game->scene) {
            scenes[i].display(game);
            break;
        }
    }

    DISPLAY(game->screen.window);
}