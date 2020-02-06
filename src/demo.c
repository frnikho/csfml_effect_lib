/**
* Nicolas SANS
* 2020-02-6 10:53
* src/demo.c
* demo
**/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "fade.h"

fade_t *fade;

int handle_input(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtKeyPressed) {
            fade->is_active = 1;
        }
    }
}

int loop(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        draw_fade(window, fade);
        handle_input(window, event);
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1600, 800};
    sfEvent event;
    sfVector2f size = {mode.width, mode.height};
    fade = init_fade(size, sfBlack, 2, FADE_IN);
    sfRenderWindow *window = sfRenderWindow_create(mode, "Effect", sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    loop(window, event);
}