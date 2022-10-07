/* File:   game.c
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  Main function */

#include <stdlib.h>
#include <stdio.h>
#include "system.h"
#include "pio.h"
#include "navswitch.h"
#include "../fonts/font5x7_1.h"
#include "text_display.h"
#include "gamelogic.h"
#include "bitmap_display.h"

#define MILLISECONDS 500
#define TIMER1_PRESCALE 1024


/** Array of rows for LED matrix where 1 represents LED on and
    0 represents off. If the player collides into one of the LEDs of wall,
    the player should lose.*/
static uint8_t wall[] =
{
    0b1100011, 0b0011111, 0b1110011, 0b1001001
};



/** Initialise timer. */
void time_init(void)
{
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;
}

/** Resets the bitmap with a random wall */
void reset_bitmap(uint8_t block[], uint8_t bitmap[])
{
    uint8_t index = rand() % 4;
    bitmap[0] = wall[index];
    bitmap[4] = block[4];
}

int main (void)
{

    bool running = 0;
    if (!running)
    {
        running = display_start_message();
    };

    /** Array of rows for LED matrix where 1 represents LED on and
        0 represents off. */
    static uint8_t bitmap[] =
    {
        0, 0, 0, 0, 0
    };

    /** The LED that the player can control */
    static uint8_t block[] =
    {
        0, 0, 0, 0, 0b1000000
    };

    system_init ();
    time_init();
    display_init();
    navswitch_init();
    uint8_t reset_bitmap_counter = 0;
    uint16_t score = 0;
    uint32_t move_player_and_bitmap_timer = MILLISECONDS * (F_CPU / TIMER1_PRESCALE) / 1000;
    bool game_over = false;
    reset_bitmap(block, bitmap);
    while (!game_over)
    {
        navswitch_update();
        display_bitmap(bitmap);
        for (uint8_t i=0; i<5; i++)
        {
            display_update();
        }

        if (navswitch_push_event_p (NAVSWITCH_SOUTH))
        {
            game_over = move_block_south(block, bitmap);
        }

        if ((TCNT1 >= move_player_and_bitmap_timer) && !game_over)
        {
            game_over = move_block_north(block, bitmap);
            if (!game_over)
            {
                game_over = move_bitmap_minus_block_east(block, bitmap);
                reset_bitmap_counter++;
                score++;
                if (reset_bitmap_counter == 5)
                {
                    reset_bitmap(block, bitmap);
                    reset_bitmap_counter = 0;
                }
            }
            TCNT1 = 0;
        }
    }

    display_score(score);

}
