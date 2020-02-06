/**
* Nicolas SANS
* 2020-02-6 23:18
* src/particle/particle_set.c
* particle_set
**/

#include "particle.h"

int particle_is_finish(particle_t *particle)
{
    return particle->is_show;
}