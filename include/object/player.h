/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** player
*/

#ifndef OBJECT_PLAYER_H
    #define OBJECT_PLAYER_H
    #include "game.h"
    #include <stdbool.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #define JUMP_STRENGTH 10.f
    #define PLAYER_GRAVITY 1.f


/**
 * @brief Player states
 */
typedef enum {
    PS_NORMAL,
    PS_JUMP,
    PS_SLIDE,
} player_state_t;


struct player_s {
    player_state_t state;
    sfSprite *sprite;
    float accel_y;  // since the player only moves up and down, only keep track of y
};


void player_update(player_t *player);
void player_jump(player_t *player);
void player_slide(player_t *player);


#endif
