/*******************************************************************************
 ** Program Filename: QueueList.hpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Specifications for QueueList class
 **              Includes definition of QueueNode struct
 ******************************************************************************/


#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP
#include <cstddef>
#include "Character.hpp"

class QueueList {
  protected:
      struct QueueNode {
          Character* fighter;
          QueueNode* next;  // Holds next node in doubly-linked list
          QueueNode* prev;  // Holds previous node in doubly-linked list

          QueueNode(Character* char_in, QueueNode* prev_in = NULL, 
                    QueueNode* next_in = NULL) {
             fighter = char_in;
             prev = prev_in;
             next = next_in;
          }
      };

      QueueNode* head;
      int team_pts;

  public:
      QueueList() { head = NULL; team_pts = 0;}
      ~QueueList();
      bool isEmpty();
      void queue_add(Character* char_in);
      Character* queue_remove();
      void set_team_pts(int pts_in);
      int get_team_pts();
      void display_list() const;
};


#endif



