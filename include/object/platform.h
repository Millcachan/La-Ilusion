/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Header file for all things
** related to platforms
*/

#ifndef OBJECT_PLATFORM_H
    #define OBJECT_PLATFORM_H
    #include "types.h"
    #include <stdbool.h>
    #include <SFML/Graphics.h>


struct platform_s {
    sfSprite *sprite;
    bool is_active;
    enum { PC_RED, PC_GREEN } color;
};


platform_t *platform_create(unsigned char color, sfTexture **textures);
void platforms_init(platform_t **platforms, sfTexture **textures);

// Utils:
sfVector2f platform_generate_position(const platform_t *previous);


#endif
