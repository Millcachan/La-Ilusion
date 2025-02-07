/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** struct.h
*/

#pragma once

#include "enum.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct cur_scene_s {
    sfMusic *music;
} cur_scene_t;

/**
 * @brief Structure screen, containing screen and window related infos.
 */
typedef struct screen_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    float height;
    float width;
} screen_t;

typedef struct musics_s {
    sfMusic *music[1];
    float volume[1];
} musics_t;

/**
 * @brief Main structure of the rpg.
 */
typedef struct game_s {
    enum scene_enum scene;
    cur_scene_t current;
    screen_t screen;
    musics_t musics;
    sfClock *clock;
    int nb_frame;
} game_t;
