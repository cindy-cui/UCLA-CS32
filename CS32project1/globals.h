//
//  globals.hpp
//  CS32project1
//
//  Created by Cindy Cui on 1/7/21.
//

#ifndef globals_h
#define globals_h

#include <stdio.h>

//prototype declarations

int randInt(int min, int max);
void clearScreen();
///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;               // max number of rows in a city
const int MAXCOLS = 30;               // max number of columns in a city
const int MAXFLATULANS = 120;         // max number of Flatulans allowed
const int INITIAL_PLAYER_HEALTH = 12;

const int UP      = 0;
const int DOWN    = 1;
const int LEFT    = 2;
const int RIGHT   = 3;
const int NUMDIRS = 4;



#endif /* globals_hpp */
