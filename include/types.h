/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Header file for types
** used in the project
*/

#ifndef TYPES_H
    #define TYPES_H


///////////////////////////////////////////
//                                       //
//               Structures              //
//                                       //
///////////////////////////////////////////

typedef struct game_s game_t;            // defined in game.h (l.45)
typedef struct screen_s screen_t;        // defined in game.h (l.24)
typedef struct musics_s musics_t;        // defined in game.h (l.36)
typedef struct scene_s scene_t;          // defined in scene.h (l.24)
typedef struct scene_ingame_s scene_ingame_t;          // defined in scene.h (l.24)
typedef struct player_s player_t;        // defined in player.h (l.29)


///////////////////////////////////////////
//                                       //
//              Enumerations             //
//                                       //
///////////////////////////////////////////

typedef enum {
    ST_NONE,

    // ST_MAIN_MENU,
    ST_INGAME
} scene_type_t;


///////////////////////////////////////////
//                                       //
//              Type Aliases             //
//                                       //
///////////////////////////////////////////

typedef void (*game_fnc_t)(game_t *);


#endif
