/* File:   bitmap_display.h
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  bitmap display header file */

#ifndef BITMAP_DISPLAY_H
#define BITMAP_DISPLAY_H

#include "system.h"

/** Turn on the LEDS in the matrix according to the given bitmap
    @param bitmap the bitmap to display
    @return this never returns. */
void display_bitmap (uint8_t bitmap[]);

/** Turn on the LEDS in a given column given a pattern
    @param row_pattern the pattern that describes which LEDs to turn on/off
           in the given column.
    @param current_column the column of the LEDs to turn on/off */
void display_column (uint8_t row_pattern, uint8_t current_column);

#endif //BITMAP_DISPLAY_H
