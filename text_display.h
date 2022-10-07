/* File:   text_display.h
Author: Noah Janssen & Haipeng Liu
# Date:   18 Oct 2021
# Descr:  text display header file */

#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "text_display.h"
#include "system.h"



bool display_start_message(void);

void display_score(uint8_t score);

#endif
