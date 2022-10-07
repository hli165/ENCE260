/* File:   gamelogic.c
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  Controller for the movement of the block and bitmap  */

#include "system.h"

/** Moves the controllable block south by one LED.
    @return 1 if the game should end, 0 otherwise.*/
bool move_block_south(uint8_t block[], uint8_t bitmap[])
{
    for (uint8_t i=0; i < 5; i++)
    {
        if (block[i] >> 6 == 0b0000001) //If block is already at the southmost LED
        {
            return false;
        }
    }
    for (uint8_t i=0; i < 5; i++)
    {
        bitmap[i] -= block[i]; // Take block out of bitmap
        block[i] *= 2; // Moves block south by 1 LED.
        if ((bitmap[i] & block[i]) != 0) // If the bitmap & block is colliding
        {
            return true;
        }
        bitmap[i] += block[i]; //Add block back into bitmap
    }
    return false;
}

/** Moves the controllable block north by one LED.
    @return 1 if the game should end, 0 otherwise.*/
bool move_block_north(uint8_t block[], uint8_t bitmap[])
{
    for (uint8_t i=0; i < 5; i++)
    {
        if (block[i] == 0b0000001) //If block is already at northmost LED
        {
            return true;
        }
    }
    for (uint8_t i=0; i < 5; i++)
    {
        bitmap[i] -= block[i]; //Take block out of bitmap
        block[i] /= 2; //Move block north
        if ((bitmap[i] & block[i]) != 0) // If the bitmap & block is colliding
        {
            return true; //game should end
        }
        bitmap[i] += block[i]; //add block back into bitmap
    }
    return false;
}

/** Moves all of the bitmap except for the controllable block east by one LED.
    @return 1 if the game should end, 0 otherwise.*/
bool move_bitmap_minus_block_east(uint8_t block[], uint8_t bitmap[])
{
    for (uint8_t i=0; i < 5; i++)
    {
        bitmap[i] -= block[i]; //Take block out of bitmap
    }
    uint8_t temp0 = bitmap[0]; // Move bitmap east
    uint8_t temp1 = bitmap[1];
    uint8_t temp2 = bitmap[2];
    uint8_t temp3 = bitmap[3];
    uint8_t temp4 = bitmap[4];
    bitmap[0] = temp4;
    bitmap[1] = temp0;
    bitmap[2] = temp1;
    bitmap[3] = temp2;
    bitmap[4] = temp3;
    for (uint8_t i=0; i < 5; i++)
    {
        if ((bitmap[i] & block[i]) != 0) //If the block is colliding with bitmap
        {
            return true;
        }
        bitmap[i] += block[i]; // Add block back into bitmap
    }
    return false;
}
