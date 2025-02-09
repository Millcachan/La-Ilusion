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

    // Compute the scale needed to cover the window with the background:
    float scale_x = (float)window_size.x / (float)texture_size.x;
    float scale_y = (float)window_size.y / (float)texture_size.y;

    // Scale the sprite to cover the whole bg
    float scale = (scale_x > scale_y) ? scale_x : scale_y;
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
}

/**
 * @brief create a texture from a file, and
 * return it if no error was encountered.
 * Exit with an error message otherwise.
 */
static sfTexture *load_texture(const char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    if (texture == NULL) {
        fprintf(stderr, "Error: Failed loading texture at %s\n", path);
        exit(ERROR);
    }

    return texture;
}

void load_menu(game_t *game)
{
    if (!game)
        return;

    if (!game->scene)
        game->scene = malloc(sizeof(scene_t));

    game->scene->data = malloc(sizeof(scene_ingame_t));
    scene_menu_t *data = game->scene->data;

    // Background Setup:
    data->background_texture = load_texture("assets/background/menu_bg.png");
    data->background = sfSprite_create();
    sfSprite_setTexture(data->background, data->background_texture, sfTrue);
    scale_image_to_window(data->background, game->screen.window);

    // Button Setup:
    data->button_texture = load_texture("assets/menu/");
    data->button;
    data->text = malloc(2 * sizeof(sfText *));
    data->text[0] = sfText_create();
    data->text[1] = sfText_create();
    data->font = sfFont_createFromFile("assets/font/FutureMillenium.ttf");
    sfText_setFont(data->text[0], data->font);
    sfText_setFont(data->text[1], data->font);
    sfText_setCharacterSize(data->text[0], 50);
    sfText_setCharacterSize(data->text[1], 50);
    sfText_setString(data->text[0], "Start");
    sfText_setString(data->text[1], "Quit");
}
