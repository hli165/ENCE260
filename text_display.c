/* File:   text_display.c
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  Controller for text display */


#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "text_display.h"
#include "system.h"
#include <stdio.h>
#include "navswitch.h"

#define PACER_RATE 500
#define MESSAGE_RATE 20


void display_score(uint8_t score) 
{
    system_init();
    char str[20];
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    sprintf(str, "Your Score is %d", score);
    tinygl_text(str);

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        
        tinygl_update();
    }
}

bool display_start_message(void) 
{
    system_init();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text("Push to start");

    pacer_init (PACER_RATE);

    while(1)
    {
        navswitch_update();
        if(navswitch_push_event_p(NAVSWITCH_PUSH))
        {
            return true;
        }
        pacer_wait();
        
        tinygl_update();
    }
    pacer_init(1);
    return false;

}
