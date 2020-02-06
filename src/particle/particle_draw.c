/**
* Nicolas SANS
* 2020-02-6 14:50
* src/particle/particle_draw.c
* particle_draw
**/

#include "particle.h"

static void check_particle_dead(particle_t *particle)
{
    if (particle->count >= particle->life) {
        particle->is_show = 0;
    } else {
        particle->count += 1;
    }
}

static void update_particle_pixels(particle_t *particle)
{
    particle->pos.x += (particle->velocity.x);
    particle->pos.y += (particle->velocity.y);
    particle->pixels[3] = particle->life / particle->count * 100;
    check_particle_dead(particle);
}

void draw_particle(sfRenderWindow *window, particle_t *particle)
{
    if (particle->is_show) {
        update_particle_pixels(particle);
        sfTexture_updateFromPixels(particle->texture, particle->pixels, 1, 1, 0, 0);
        sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
        sfVector2f p = {particle->pos.x, particle->pos.y};
        sfSprite_setPosition(particle->sprite, p);
        sfRenderWindow_drawSprite(window, particle->sprite, 0);
    }
}