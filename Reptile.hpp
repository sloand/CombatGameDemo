/*******************************************************************************
 ** Program Filename: Reptile.hpp
 ** Author: Dennis Sloan
 ** Date: 5/151515151515151515151515151515/15
 ** Description: Specifications for Reptile Class
 ******************************************************************************/


#ifndef REPTILE_HPP
#define REPTILE_HPP
#include <string>
#include "Character.hpp"

using namespace std;


class Reptile : public Character {
  public:
      Reptile(string name_in) : Character (name_in, 7, 18) {};
      virtual void set_attack();
      virtual void set_defense();

};


#endif



