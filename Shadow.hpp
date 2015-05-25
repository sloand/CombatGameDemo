/*******************************************************************************
 ** Program Filename: Shadow.hpp
 ** Author: Dennis Sloan
 ** Date: 5/15/15
 ** Description: Specifications for Shadow class
 ******************************************************************************/


#ifndef SHADOW_HPP
#define SHADOW_HPP
#include <string>
#include "Character.hpp"

using namespace std;


class Shadow : public Character {
  private:
      bool special;

  public:
      Shadow(string name_in) : Character (name_in, 0, 12) {};
      void set_special(bool special_in); 
      bool get_special();
      virtual void set_attack();
      virtual void set_defense();
      void defend(Character* attacker);
};


#endif



