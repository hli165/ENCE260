/* File:   bitmap_display .c
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  Used to display the bitmap on LED matrix */


#include "system.h"
#include "pio.h"


/** Define PIO pins driving LED matrix rows.  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO,
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

/** Turn on the LEDS in a given column given a pattern
    @param row_pattern the pattern that describes which LEDs to turn on/off
           in the given column.
    @param current_column the column of the LEDs to turn on/off */
void display_column (uint8_t row_pattern, uint8_t current_column)
{

    for (uint8_t col=0; col < 5; col++)
    {
        pio_output_high(cols[col]);
    }
    for (uint8_t current_row=0; current_row < 7; current_row++)
    {
        if ((row_pattern >> current_row) & 1)
        {
            pio_output_low(rows[current_row]);
        }
        else
        {
            pio_output_high(rows[current_row]);
        }
    }
    pio_output_low(cols[current_column]);
}

/** Turn on the LEDS in the matrix according to the given bitmap
    @param bitmap the bitmap to display
    @return this never returns. */
void display_bitmap (uint8_t bitmap[])
{
    uint8_t current_column = 0;
    while (current_column < 5)
    {
        display_column(bitmap[current_column], current_column);
        current_column++;
    }
}



