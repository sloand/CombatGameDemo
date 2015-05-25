/*******************************************************************************
 ** Program Filename: Reptile.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for Reptile class:
 **                  set_attack method
 **                  set_defense method
 ******************************************************************************/


#include <iostream>
#include "Reptile.hpp"


/*******************************************************************************
 ** Function: set_attack
 ** Description:  Rolls 3 6-sided dice, sets attack to total of rolls
 ** Parameters: None
 ******************************************************************************/

void Reptile::set_attack() {
    int roll1 = 0;
    int roll2 = 0;
    int roll3 = 0;

    dice1.roll();
    roll1 = dice1.get_roll_total();    
    dice1.roll();
    roll2 = dice1.get_roll_total();
    dice1.roll();
    roll3 = dice1.get_roll_total();
    attack = roll1 + roll2 + roll3;
}

 
/*******************************************************************************
 ** Function: set_defense
 ** Description: Rolls 1 6-sided die to set defense value
 ** Parameters: None
 ******************************************************************************/

void Reptile::set_defense() {
    int roll1 = 0;

    dice1.roll();
    roll1 = dice1.get_roll_total();    
    defense = roll1;
 
}



