/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Header file for all things
** related to asset management
*/

#ifndef CORE_ASSETS_H
    #define CORE_ASSETS_H
    #include <SFML/Graphics.h>


sfSprite *load_sprite(const char *path);
void unload_sprite(sfSprite *sprite);


#endif
