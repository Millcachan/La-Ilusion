/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** scene.h
*/

#ifndef SCENE_H
    #define SCENE_H
    #include "types.h"
    #include "object/player.h"
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>


/**
 * @brief All different scene types
 * /!\ Do not change the order of these
 */



/**
 * @brief Structure representing a scene.
 */
struct scene_s {
    scene_type_t type;
    game_fnc_t load;
    game_fnc_t event_manager;
    game_fnc_t update;
    game_fnc_t display;
    game_fnc_t free;
    void *data;
};

struct scene_ingame_s {
    sfSprite **background;
    sfTexture **background_texture;
    player_t *player;
};


void load_ingame(game_t *game);
void update_ingame(game_t *game);
void event_ingame(game_t *game);
void display_ingame(game_t *game);
void free_ingame(game_t *game);

/**
 * @brief Every scene enum and function pointer.
 */
static const scene_t scenes[] = {
    {ST_NONE, NULL, NULL, NULL, NULL, NULL, NULL},
    // {ST_MAIN_MENU, NULL, NULL, NULL, NULL, NULL},
    {ST_INGAME, load_ingame, event_ingame, update_ingame, display_ingame, free_ingame, NULL}
};


void free_current_scene(game_t *game);
void change_scene(game_t *game, scene_type_t scene_type);



#endif
