/*******************************************************************************
 ** Program Filename: BlueMen.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for BlueMen class:
 **                  set_attack method
 **                  set_defense method
 ******************************************************************************/


#include <iostream>
#include "BlueMen.hpp"

using std::cout;
using std::endl;


/*******************************************************************************
 ** Function: set_attack
 ** Description: Rolls 2 ten-sided dice; sets attack value to total of rolls
 ** Parameters: None
 ******************************************************************************/

void BlueMen::set_attack() {
    int roll1 = 0;
    int roll2 = 0;

    dice2.roll();
    roll1 = dice2.get_roll_total();    
    dice2.roll();
    roll2 = dice2.get_roll_total();
    attack = roll1 + roll2;
}

 
/*******************************************************************************
 ** Function: set_defense
 ** Description:  Rolls 2 six-sided dice; sets defense value to total of rolls
 ** Parameters: None
 ******************************************************************************/

void BlueMen::set_defense() {
    int roll1 = 0;
    int roll2 = 0;

    dice1.roll();
    roll1 = dice1.get_roll_total();    
    dice1.roll();
    roll2 = dice1.get_roll_total();
    defense = roll1 + roll2;
 
}



