/*******************************************************************************
 ** Program Filename: Barbarian.hpp
 ** Author: Dennis Sloan
 ** Date: 5/15/15
 ** Description: Specifications for Barbarian class
 ******************************************************************************/


#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <string>
#include "Character.hpp"

using namespace std;


class Barbarian : public Character {
  public:
      Barbarian(string name_in) : Character (name_in, 0, 12) {};
      virtual void set_attack();
      virtual void set_defense();

};


#endif



