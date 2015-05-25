/*******************************************************************************
 ** Program Filename: Goblin.hpp
 ** Author: Dennis Sloan
 ** Date: 5/15/15
 ** Description: Specifications for Goblin class
 ******************************************************************************/


#ifndef GOBLIN_HPP
#define GOBLIN_HPP
#include <string>
#include "Character.hpp"

using namespace std;


class Goblin : public Character {
  bool achilles;

  public:
      Goblin(string name_in) : Character (name_in, 3, 8) {};
      void set_achilles(bool achilles_in); 
      bool get_achilles();
      void print_stats(Character* attacker, int net_damage);
      virtual void set_attack();
      virtual void set_defense();
      void defend(Character* attacker);
};


#endif



