/*******************************************************************************
 ** Program Filename: Shadow.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for Shadow class:
 **                  set_attack method
 **                  set_defense method
 ******************************************************************************/


#include <iostream>
#include "Shadow.hpp"

using std::cout;
using std::endl;


void Shadow::set_special(bool special_in) {
    special = special_in;
}


bool Shadow::get_special() {
    return special;
}

/*******************************************************************************
 ** Function: set_attack
 ** Description:  Rolls 2 ten-sided dice and totals rolls; sets attack to total.
 ** Parameters: None
 ******************************************************************************/

void Shadow::set_attack() {
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
 ** Description: Rolls 2 six-sided dice and totals rolls; sets defense value to 
 **              total
 ** Parameters: None
 ******************************************************************************/

void Shadow::set_defense() {
    int roll1 = 0;
    int roll2 = 0;

    dice1.roll();
    roll1 = dice1.get_roll_total();    
    dice1.roll();
    roll2 = dice1.get_roll_total();
    defense = roll1 + roll2;
 
}


/*******************************************************************************
 ** Description: This method is called when another object attacks a Shadow.
 **              Since the Shadow is not truly where it appears to be 50% of 
 **              time, this method toggles the Shadow's special variable 
 **              between true and false.  When true, no damage is sustained.
 **              When false, this method sets the opponent's attack value and 
 **              the Shadow's defense value.  It then substracts the Shadow's 
 **              defense value from the attack, then subtracts the armor to
 **              arrive a net damage value.  If that value is above 0, it is
 **              subtracted from the Shadow's strength points.  If it is 0 or
 **              less, the Shadow's strength points are set to 0 and the game
 **              ends.
 ** Parameters: Character* attacker - the Shadow's opponent
 ******************************************************************************/

void Shadow::defend(Character* attacker) {
    int damage = 0;
    int net_damage = 0;
    int new_strength;

    if (this->get_special()) {
        cout << "Attack yields no damage - " << this->get_name()
             << " is not there!" << endl;
        this->set_special(false);
    }
    else {
        attacker->set_attack();
        this->set_defense();

        damage = attacker->get_attack() - this->get_defense();

        if ((damage - armor) > 0) {
            net_damage = damage - this->get_armor();
        }
        else {
            net_damage = 0;
        }

        new_strength = this->get_strength_pts() - net_damage;

        if (new_strength >= 0) {
            this->set_strength_pts(new_strength);
        }
        else {
            this->set_strength_pts(0);
        }

        this->print_stats(attacker, net_damage);

        this->set_special(true);
    }
}


