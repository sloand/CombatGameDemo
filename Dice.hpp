/*******************************************************************************
 ** Program Filename: Dice.hpp
 ** Author: Dennis Sloan
 ** Date: 05/01/15
 ** Description: Specifications for Dice class
 ** Input:
 ** Output:
 ******************************************************************************/


#ifndef DICE_HPP
#define DICE_HPP


class Dice {
  private:
      int sides;
      int roll_total;

  public:
      Dice();
      Dice(int sides_in);
      void set_sides(int sides_in);
      int get_sides();
      void set_roll_total(int roll_tot);
      int get_roll_total();
      void roll();
};


#endif



