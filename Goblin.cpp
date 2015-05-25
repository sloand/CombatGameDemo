/*******************************************************************************
 ** Program Filename: Goblin.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for Goblin class:
 **                  set_attack method
 **                  set_defense method
 ******************************************************************************/


#include <iostream>
#include "Goblin.hpp"

using std::cout;
using std::endl;


void Goblin::set_achilles(bool achilles_in) {
    achilles = achilles_in;
}


bool Goblin::get_achilles() {
    return achilles;
}


/*******************************************************************************
 ** Function: set_attack
 ** Description: Rolls 2 6-sided dice; sets attack value to total of rolls
 **              If a 12 is rolled, achilles specialty is set to true, cutting
 **              all further attacks on this object in half
 ** Parameters: None
 ******************************************************************************/

void Goblin::set_attack() {
    int roll1 = 0;
    int roll2 = 0;

    dice1.roll();
    roll1 = dice1.get_roll_total();    
    dice1.roll();
    roll2 = dice1.get_roll_total();
    attack = roll1 + roll2;

    if (attack == 12) {
        this->set_achilles(true);
    }
    else {
    }
}

 
/*******************************************************************************
 ** Function: set_defense
 ** Description:  Rolls one 6-sided die, sets defense value to roll total
 ** Parameters: None
 ******************************************************************************/

void Goblin::set_defense() {
    int roll1 = 0;

    dice1.roll();
    roll1 = dice1.get_roll_total();    
    defense = roll1;
}


/*******************************************************************************
 ** Function: print_stats
 ** Description: Prints summary of attack and resulting damage;
 **              Prints special message if achilles specialty is in effect
 ** Parameters: None
 ******************************************************************************/

void Goblin::print_stats(Character* attacker, int net_damage) {
    int attack = 0;

    if (this->get_achilles() == true) {
        cout << "Attack of " << attacker->get_attack() << " reduced to " 
             << attacker->get_attack() / 2 << " due to cut Achilles heel "
             << "meets defense of " << this->get_defense() << endl;
        cout << "and armor of "              << this->get_armor()  
             << ", resulting in net damage of " << net_damage << "!" 
             << endl;
 
    } 
    else {
        cout << "Attack of " << attacker->get_attack() << " meets defense of "
             << this->get_defense() << " and armor of " << this->get_armor()
             << ", resulting in net damage of " << net_damage << "!" << endl
             << endl;
    }
}


/*******************************************************************************
 ** Function: defend
 ** Description:  Processes attack by another object on Goblin
 **               Sets attackers' attack value, Goblin's defense value
 **               If achilles specialty is in effect, attack is cut in half
 **               Attack, defense, and armor values are used to set damage and
 **                  update strength points
 **               print_stats method is called
 ** Parameters: None
 ******************************************************************************/

void Goblin::defend(Character* attacker) {
    int damage = 0;
    int net_damage = 0;
    int new_strength;

    attacker->set_attack();
    this->set_defense();

    if (this->get_achilles() == true) {
        damage = (attacker->get_attack() / 2) - this->get_defense();
    }
    else {
        damage = attacker->get_attack() - this->get_defense();
    }

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
}


