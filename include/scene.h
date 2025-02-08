/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** scene.h
*/

#ifndef SCENE_H
    #define SCENE_H
    #include <types.h>
    #include <stdlib.h>


/**
 * @brief All different scene types
 * /!\ Do not change the order of these
 */
typedef enum {
    ST_NONE,

    ST_MAIN_MENU,
} scene_type_t;


/**
 * @brief Structure representing a scene.
 */
struct scene_s {
    scene_type_t type;
    game_fnc_t load;
    game_fnc_t event_manager;
    game_fnc_t update;
    game_fnc_t display;
};


/**
 * @brief Every scene enum and function pointer.
 */
static const scene_t scenes[] = {
    {ST_NONE, NULL, NULL, NULL, NULL},  // /!\ DO NOT CHANGE ORDER (indices correspond to enum values)
    // {MENU, load, event, update, display},
};


void free_current_scene(game_t *game);
void change_scene(game_t *game, scene_type_t scene_type);


#endif
