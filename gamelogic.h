/* File:   gamelogic.h
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  game logic header file */

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "system.h"

/** Moves the controllable block south by one LED.
    @return 1 if the game should end, 0 otherwise.*/
bool move_block_south(uint8_t block[], uint8_t bitmap[]);
/** Moves the controllable block north by one LED.
    @return 1 if the game should end, 0 otherwise.*/
bool move_block_north(uint8_t block[], uint8_t bitmap[]);

/** Moves all of the bitmap except for the controllable block east by one LED.
    @return 1 if the game should end, 0 otherwise.*/
bool move_bitmap_minus_block_east(uint8_t block[], uint8_t bitmap[]);

#endif //GAMELOGIC_H
