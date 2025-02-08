/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** player
*/

#pragma once

#include "game.h"
#include <stdbool.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#define JUMP_STRENGTH 10.f
#define PLAYER_GRAVITY 1.f

// player actions
typedef enum {
    PL_JUMP,
    PL_NORMAL,
    PL_SLIDE,
} player_state_t;

typedef struct player_s {
    sfSprite *pl_sprite;
    float accel_y;  // since the player only moves up and down, only keep track of y
    player_state_t *pl_state;
} player_t;


void player_update(player_t *player);
void player_jump(player_t *player);
void player_slide(player_t *player);
