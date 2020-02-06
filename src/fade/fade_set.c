/**
* Nicolas SANS
* 2020-02-6 11:37
* src/fade/fade_set.c
* fade_set
**/

#include "fade.h"

int fade_is_active(fade_t *fade)
{
    return fade->is_active;
}

int fade_is_finish(fade_t *fade)
{
    return fade->is_finish;
}