/*******************************************************************************
 ** Program Filename: StackList.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for StackList class
 **              Includes definition of StackNode struct
 ******************************************************************************/


#ifndef STACKLIST_HPP
#define STACKLIST_HPP
#include <cstddef>
#include "Character.hpp"


class StackList {
  protected:
      struct StackNode {
          Character* loser;
          StackNode* next;

          StackNode(Character* char_in, StackNode* next_in = NULL){
              loser = char_in;
              next = next_in; // Holds link to next node in linked list 
          }
      };

      StackNode* head;

  public:
      StackList() { head = NULL; }
      ~StackList();
      void stack_add(Character* char_in);
      void get_finishers();
      Character* stack_remove();
      void display_list() const;
};


#endif



