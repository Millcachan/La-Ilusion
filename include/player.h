/*
** EPITECH PROJECT, 2025
** LaIlusion
** File description:
** player
*/

#pragma once

#include "struct.h"
#include <stdbool.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

// player actions
typedef enum {
    PL_JUMP,
    PL_NORMAL,
    PL_SLIDE,
} player_state_t;

typedef struct player_s {
    sfSprite *pl_sprite;
    sfIntRect *hitbox;
    sfVector2f position;
    sfVector2f scale;
    player_state_t *pl_state;
    bool jumping;
} player_t;

void check_jump(game_t *game);
