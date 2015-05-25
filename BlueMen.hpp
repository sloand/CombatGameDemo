/*******************************************************************************
 ** Program Filename: BlueMen.hpp
 ** Author: Dennis Sloan
 ** Date: 5/15/15
 ** Description: Specifications for BlueMen class
 ******************************************************************************/


#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <string>
#include "Character.hpp"

using namespace std;


class BlueMen : public Character {
  public:
      BlueMen(string name_in) : Character (name_in, 6, 12) {};
      virtual void set_attack();
      virtual void set_defense();

};


#endif



