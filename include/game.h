/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** Header file for core
** game structures
*/

#ifndef GAME_H
    #define GAME_H
    #include <types.h>
    #include <scene.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>


/**
 * @brief Structure screen, containing screen
 * and window related data
 */
struct screen_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    float height;
    float width;
};

/**
 * @brief Structure containing all of the game's music
 * tracks, as well as their associated volumes
 */
struct musics_s {
    sfMusic *music[1];
    float volume[1];
};


/**
 * @brief Main structure of the game
 */
struct game_s {
    // Scene:
    scene_type_t scene_type;
    scene_t *scene;

    // Music:
    musics_t musics;
    sfMusic *current_music;

    // Game Lifetime:
    screen_t screen;
    sfClock *clock;
    unsigned int nb_frame;
};


#endif
