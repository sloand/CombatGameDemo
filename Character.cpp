/*******************************************************************************
 ** Program Filename: Character.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Implementation of Character Class, including methods:
 **                 Character Constructor
 **                 defend
 **                 print_stats
 **                 heal
 ******************************************************************************/


#include <iostream>
#include <string> 
#include "Character.hpp"

using namespace std;


/*******************************************************************************
 ** Function: Character constructor
 ** Description: This method constructs a Character object as a base for all
 **              inherited class objects.  It creates two dice objects that can
 **              be used for gameplay (one 6-sided, one 10-sided). It also sets
 **              the object's armor and strength values. 
 ** Parameters:  string name_in - name for object
 **              int armor_in - armor value for object
 **              int strength_in - strength value for object
 ******************************************************************************/

Character::Character(string name_in, int armor_in, int strength_in) {
    Dice dice1(6);      // 6-sided die 
    Dice dice2(10);     // 10-sided die
    set_name(name_in);
    set_armor(armor_in);
    set_strength_pts(strength_in);
    tourn_pts = 0;
}


/*******************************************************************************
 ** Function: defend
 ** Description: This is a base clase defend method, for those inherited classes **              that do not have special attack defend needs.  The method does
 **              the following:
 **                  Calls attacker's set_attack method to set attack value
 **                  Calls defender's set_defense method to set defense value
 **                  Uses attack, defense, and armor values to determine and
 **                     apply damage and adjust strength points
 **              Calls print_stats method to print post-attack stats  
 ** Parameters:  Character* attacker - points to attacking object
 ******************************************************************************/

void Character::defend(Character* attacker) {
    int damage = 0;
    int net_damage = 0;
    int new_strength;

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
}


/*******************************************************************************
 ** Function: print_stats
 ** Description: This method prints information about each round of battle
 ** Parameters:  Character* attacker - the attacking object
 **              int net_damage - amt of damage sustained by defender
 ******************************************************************************/

void Character::print_stats(Character* attacker, int net_damage) {
    cout << "Attack of " << attacker->get_attack() << " meets defense of "
         << this->get_defense() << " and armor of " << this->get_armor()
         << ", resulting in net damage of " << net_damage << "!" << endl;
}


/*******************************************************************************
 ** Function: heal
 ** Description: This method restores 1 strength point after a victory 
 ** Parameters:  None
 ******************************************************************************/

void Character::heal() {
    int str_pts = get_strength_pts();

    set_strength_pts(str_pts + 1);
}


/*
 * Mutator and accessor methods follow
 */ 


int Character::get_attack() {
    return attack;
}


int Character::get_defense() {
    return defense;
}


void Character::set_name(string name_in) {
    name = name_in;
}


string Character::get_name() {
    return name;
}


void Character::set_armor(int arm_in) {
    armor = arm_in;
}


int Character::get_armor() {
    return armor;
}


void Character::set_strength_pts(int strength_in) {
    strength_pts = strength_in;
}


int Character::get_strength_pts() {
    return strength_pts;
}


void Character::set_tourn_pts(int pts_in) {
    tourn_pts += pts_in;
}


int Character::get_tourn_pts() {
    return tourn_pts;
} 
