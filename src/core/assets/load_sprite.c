/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Implementation for
** load_sprite
*/

#include "assets.h"
#include "macro.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Load a sprite from a given path (situated at project root)
 */
sfSprite *load_sprite(const char *path)
 {
     sfSprite *sprite = sfSprite_create();
     sfTexture *texture = sfTexture_createSrgbFromFile(path, NULL);

     if (texture == NULL) {
         fprintf(stderr, "Error: Failed to load sprite located at %s", path);
         exit(ERROR);
     }

     sfSprite_setTexture(sprite, texture, sfFalse);

     return sprite;  // the texture can still be freed since it's stored in the sprite
 }
