/**
* Nicolas SANS
* 2020-02-6 11:7
* include/fade.h
* fade
**/

#ifndef CSFML_EFFECT_LIB_FADE_H
#define CSFML_EFFECT_LIB_FADE_H

#include <SFML/Graphics.h>

enum FADE_TYPE {FADE_IN = 0, FADE_OUT = 1};

typedef struct fade_s {
    sfVector2f screen_size;
    sfRectangleShape *shape;
    sfColor color;
    sfVector2f size;
    float speed;
    int fade_in;
    int is_finish;
    int is_active;
} fade_t;

fade_t *init_fade(sfVector2f size, sfColor color, float speed, int in);
void draw_fade(sfRenderWindow *window, fade_t *fade);
void dispose_fade(fade_t *fade);
void reset_fade(fade_t *fade);
int fade_is_active(fade_t *fade);
int fade_is_finish(fade_t *fade);

#endif
