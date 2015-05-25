/*******************************************************************************
 ** Program Filename: Character.hpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for Character class
 ******************************************************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include "Dice.hpp"

using namespace std;


class Character {
  protected:
      Dice dice1;
      Dice dice2;
      string name;
      int attack;
      int defense;
      int armor;
      int strength_pts;
      int tourn_pts;
      
  public:
      Character(string name_in, int armor_in, int strength_in);
      void set_name(string name_in);
      string get_name();
      virtual void set_attack() = 0;
      int get_attack();
      virtual void set_defense() = 0;
      int get_defense();
      void set_armor(int arm_in);
      int get_armor();
      void set_strength_pts(int strength_in);
      int get_strength_pts();
      void print_stats(Character* attacker, int net_damage);
      virtual void defend(Character* attacker);
      void heal(); 
      void set_tourn_pts(int pts_in);
      int get_tourn_pts();
};


#endif



