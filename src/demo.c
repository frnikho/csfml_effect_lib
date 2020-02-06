/**
* Nicolas SANS
* 2020-02-6 10:53
* src/demo.c
* demo
**/

#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "particle.h"

particle_t **particle;

static int init(void)
{
    time_t t;
    srand((unsigned) time(&t));
    particle = malloc(500 * sizeof(particle_t));
    sfVector2f pos = {800, 400};
    for (int i = 0; i < 500; i++) {
        int life = (rand() % 12);
        int r = (rand() % 255);
        int g = (rand() % 255);
        int b = (rand() % 255);
        sfColor color = sfColor_fromRGBA(r, g, b, 255);
        particle[i] = init_particle(pos, 10, life, color);
    }
}

int handle_input(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtKeyPressed) {
            for (int i = 0; i < 500; i++) {
                particle[i]->is_show = 1;
            }
        }
    }
}

int loop(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        for (int i = 0; i < 500; i++) {
            draw_particle(window, particle[i]);
        }
        handle_input(window, event);
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1600, 800};
    sfEvent event;
    init();
    sfRenderWindow *window = sfRenderWindow_create(mode, "Effect", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    loop(window, event);
}