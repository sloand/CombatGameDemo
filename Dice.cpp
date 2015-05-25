/*******************************************************************************
 ** Program Filename: Dice.cpp
 ** Author: Dennis Sloan
 ** Date: 05/01/15
 ** Description: Implementation of Dice class, including roll method
 ** Input:
 ** Output:
 ******************************************************************************/


#include <ctime>
#include <cstdlib>
#include "Dice.hpp"


Dice::Dice() {
    set_sides(6);
    set_roll_total(0);
    unsigned seed;
    seed = time(NULL);
    srand(seed);
}


Dice::Dice(int sides_in){
    set_sides(sides_in);
    set_roll_total(0);
    unsigned seed;
    seed = time(NULL);
    srand(seed);
}


void Dice::set_sides(int sides_in) {
    sides = sides_in;
}


int Dice::get_sides() {
    return sides;
}


void Dice::set_roll_total(int roll_tot_in) {
    roll_total = roll_tot_in;
}


int Dice::get_roll_total() {
   return roll_total;
} 


/*******************************************************************************
 ** Function:
 ** Description:
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 ******************************************************************************/

void Dice::roll() {
    int roll_tot = rand() % get_sides() + 1;
    set_roll_total(roll_tot); 
} 

