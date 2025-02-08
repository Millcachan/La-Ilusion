/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** scene.h
*/

#pragma once

#include "struct.h"
#include "enum.h"

void free_current_scene(cur_scene_t *current, game_t *game);

/**
 * @brief Structure representing a scene.
 */
typedef struct scene_s {
    enum scene_enum scene; /**The scene enum.*/
    void (*load)(game_t *game); /**Function point to load the scene*/
    void (*event_manager)(game_t *game); /**Function pointer for event.*/
    void (*update)(game_t *game); /**Function pointer for scene update.*/
    void (*display)(game_t *game); /**Function pointer for scene display.*/
} scene_t;

/**
 * @brief Every scene enum and function pointer.
 */
static const struct scene_s scenes[] = {
    // {MENU, load, event, update, display},
    {NONE, NULL, NULL, NULL, NULL}
};