/*
** EPITECH PROJECT, 2024
** La-Ilusi-n
** File description:
** load_menu.c
*/

#include "game.h"
#include "macro.h"
#include <string.h>

static void scale_image_to_window(sfSprite* sprite, sfRenderWindow* window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u texture_size = sfTexture_getSize(sfSprite_getTexture(sprite));
    float scale_x = (float)window_size.x / (float)texture_size.x;
    float scale_y = (float)window_size.y / (float)texture_size.y;
    float scale = (scale_x < scale_y) ? scale_x : scale_y;

    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
}

void load_ingame(game_t *game)
{
    if (!game)
        return;
    if (!game->scene) {
        game->scene = malloc(sizeof(scene_t));
    }
    game->scene->data = malloc(sizeof(scene_ingame_t));

    scene_ingame_t *data = game->scene->data;
    data->background = malloc(sizeof(sfSprite *) * 6);
    data->background_texture = malloc(sizeof(sfTexture *) * 6);

    for (int i = 0; i < 5; i++) {
        char filePath[256];
        snprintf(filePath, sizeof(filePath), "assets/background/layer_%d.png", i);  
        data->background_texture[i] = sfTexture_createFromFile(filePath, NULL);
        sfTexture_setRepeated(data->background_texture[i], sfTrue);
        data->background[i] = sfSprite_create();
        sfSprite_setTexture(data->background[i], data->background_texture[i], sfTrue);
        scale_image_to_window(data->background[i], game->screen.window);
    }
    data->background[5] = NULL;
    data->background_texture[5] = NULL;
}
