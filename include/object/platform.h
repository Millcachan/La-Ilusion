/*
** EPITECH PROJECT, 2024
** Project - La Ilusion
** File description:
** Header file for all things
** related to platforms
*/

#ifndef OBJECT_PLATFORM_H
    #define OBJECT_PLATFORM_H
    #include <stdbool.h>
    #include <SFML/Graphics.h>


struct platform_s {
    sfSprite *sprite;
    float accel_x;
    bool is_active;
};


#endif
