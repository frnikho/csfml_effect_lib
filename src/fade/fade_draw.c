/**
* Nicolas SANS
* 2020-02-6 11:36
* src/fade/fade_draw.c
* fade_draw
**/

#include <SFML/Graphics.h>
#include "fade.h"

static void update_fade(fade_t *fade)
{
    if (fade->color.a >= 254 - fade->speed) {
        fade->color.a = 0;
        fade->is_finish = 1;
        fade->is_active = 0;
    } else {
        fade->color.a += fade->speed;
    }
    sfRectangleShape_setFillColor(fade->shape, fade->color);
}

void draw_fade(sfRenderWindow *window, fade_t *fade)
{
    if (fade->is_active) {
        update_fade(fade);
        sfRenderWindow_drawRectangleShape(window, fade->shape, 0);
    }
}