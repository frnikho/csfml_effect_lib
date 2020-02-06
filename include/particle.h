/**
* Nicolas SANS
* 2020-02-6 14:45
* include/particle.h
* particle
**/

#ifndef CSFML_EFFECT_LIB_PARTICLE_H
#define CSFML_EFFECT_LIB_PARTICLE_H

#include <SFML/Graphics.h>

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f velocity;
    sfUint8 *pixels;
    float life;
    int speed;
    int count;
    int is_show;
    sfColor color;
    sfTexture *texture;
    sfSprite *sprite;
} particle_t;

particle_t *init_particle(sfVector2f pos, int count, float life, sfColor color);

void draw_particle(sfRenderWindow *window, particle_t *particle);

#endif
