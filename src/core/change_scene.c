/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** change_scene.c
*/

#include "enum.h"
#include "struct.h"
#include "macro.h"
#include "scene.h"
#include "sound.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief  Call this function wherever to change the current scene.
 */
void change_scene(game_t *game, enum scene_enum scene)
{
    sfMusic_stop(game->current.music);
    free_current_scene(&game->current, game);

    game->scene = scene;

    for (int i = 0; scenes[i].scene != NONE; i++) {
        if (scenes[i].scene == game->scene) {
            scenes[i].load(game);
            break;
        }
    }
}
