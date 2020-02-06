/**
* Nicolas SANS
* 2020-02-6 11:7
* src/fade/fade.c
* fade
**/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "fade.h"

static void init_shape(fade_t *fade)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {fade->screen_size.x, fade->screen_size.y};
    fade->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(fade->shape, size);
    sfRectangleShape_setPosition(fade->shape, pos);
    sfRectangleShape_setFillColor(fade->shape, fade->color);
}

fade_t *init_fade(sfVector2f size, sfColor color, float speed, int in)
{
    fade_t *fade = malloc(sizeof(fade_t));
    fade->screen_size = size;
    fade->color = color;
    if (in) {
        fade->color.a = 0;
    } else {
        fade->color.a = 255;
    }
    fade->speed = speed;
    fade->is_finish = 0;
    fade->is_active = 0;
    fade->fade_in = in;
    init_shape(fade);
    return (fade);
}

void reset_fade(fade_t *fade)
{
    init_shape(fade);
    fade->is_finish = 0;
    fade->is_active = 0;
}

void dispose_fade(fade_t *fade)
{
    sfRectangleShape_destroy(fade->shape);
    free(fade);
}