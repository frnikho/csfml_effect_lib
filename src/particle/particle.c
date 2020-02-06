/**
* Nicolas SANS
* 2020-02-6 10:59
* src/particle.c
* particle
**/

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "particle.h"

static void init_particle_pixels(particle_t *particle)
{
    particle->pixels = malloc(0);
    particle->pixels[0] = particle->color.r;
    particle->pixels[1] = particle->color.g;
    particle->pixels[2] = particle->color.b;
    particle->pixels[3] = particle->color.a;
}

static void init_particle_velocity(particle_t *particle)
{
    float r1 = ((float) rand() / (float)(RAND_MAX)) * particle->speed;
    float r2 = ((float) rand() / (float)(RAND_MAX)) * particle->speed;
    float dx = ((float)rand()/(float)(RAND_MAX)) * r1 - r1 / 2;
    float dy = ((float)rand()/(float)(RAND_MAX)) * r2 - r2 / 2;
    if (dy == 0)
        dy++;
    if (dx == 0)
        dx++;
    sfVector2f velocity = {dx, dy};
    particle->velocity = velocity;
}

particle_t *init_particle(sfVector2f pos, int speed, float life, sfColor color)
{
    particle_t *particle = malloc(sizeof(particle_t));
    particle->pos = pos;
    particle->speed = speed;
    particle->color = color;
    particle->life = life * 10;
    particle->count = 0;
    particle->is_show = 0;
    particle->texture = sfTexture_create(1, 1);
    init_particle_velocity(particle);
    init_particle_pixels(particle);
    particle->sprite = sfSprite_create();
    return (particle);
}