/*******************************************************************************
 ** Program Filename: StackList.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Implementation of StackList class methods:
 **              stack_add (adds node to StackList)
 **              stack_remove (removes node from StackList)
 **              display_list (displays StackList)
 ******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include "StackList.hpp"

using namespace std;


/*******************************************************************************
 ** Function: stack_add
 ** Description: Adds node to StackList
 ** Parameters: int num_in - value for node to be added
 ******************************************************************************/

void StackList::stack_add(Character* char_in) {

    StackNode* old_head; // holds head of list while new head is created

    //cout << "Adding " << num_in << endl;

    // If head does not exist, new node becomes head
    if (head == NULL) {
        head = new StackNode(char_in);
    }
    // If head exists, new node is created with old head has "next" value
    else {
        old_head = head;
        head = new StackNode(char_in, old_head);
    }

}


/*******************************************************************************
 ** Function: stack_remove
 ** Description: Removes an item from StackList - FILO order 
 ** Parameters: None
 *****************************************************************************/

Character* StackList::stack_remove() {
    Character* ret_char;

    StackNode* node_ptr; // Stores node being worked with
    StackNode* prev_node_ptr; // Stores "previous" node to node being worked w/

    // If there is no head, StackList is empty - nothing to be removed
    if (!head) {
       return NULL;
    }


    else {
       ret_char = head->loser;
       node_ptr = head;
       head = head->next;
       delete node_ptr;
       return ret_char;
    }

}


/*******************************************************************************
 ** Function: get_finishers
 ** Description: This method determines first, second, and third place finishers **              at the end of a game in the following steps:
 **                  1.  Moves all players from retire pile to players vector
 **                  2.  Sorts vector by Character objects' tourn_pts value
 **                  3.  Compares values to determine placement
 **                  4.  Prints finishers 
 ** Parameters: None
 *****************************************************************************/

void StackList::get_finishers() {
    vector <StackNode*> players;
    StackNode* node_ptr = head;
    StackNode* maxPlayer;
    int maxVal;
    int maxIndex;
    int size;
    int prev_pts;
    int index;
    int place;
    int curr_pts;

    // Push all elements of StackList into a vector
    while (node_ptr) {

        players.push_back(node_ptr);
        node_ptr = node_ptr->next;

    }

    size = players.size();

    /* 
     * Selection sort on vector
     * Places all nodes in Stacklist in descending order of Character objects' 
     * tourn_pts value
     */  
    for (int start = 0; start < size; start++) {

        maxIndex = start;
        maxPlayer = players[start];
        maxVal = players[start]->loser->get_tourn_pts();

        for (int index = start + 1; index < size; index++) {

            if (players[index]->loser->get_tourn_pts() >= maxVal) {

                maxVal = players[index]->loser->get_tourn_pts();
                maxPlayer = players[index];
                maxIndex = index;

            }

        }

        players[maxIndex] = players[start];
        players[start] = maxPlayer;

    }

    // Print player's final points
    cout << "\nFinal Player Points:" << endl;

    for (int i = 0; i < size; i++) {
        cout << players[i]->loser->get_name() << ": "
             << players[i]->loser->get_tourn_pts() << endl;
    }

    prev_pts = players[0]->loser->get_tourn_pts();
    index = 0;
    place = 1;

    // Print finishers
    cout << "\n1st Place Finishers:" << endl;
    cout << players[0]->loser->get_name() << endl;
    index++;

    // Determine finishers by comparing Charcter objects' tourn_pts values
    while (place < 4 && index < size) {

        curr_pts = players[index]->loser->get_tourn_pts();

        if (curr_pts != prev_pts) {
            place++;
            if (place == 2) {
                cout << "\n2nd Place Finishers:" << endl;
            }
            else if (place == 3) {
                cout << "\n3rd Place Finishers:" << endl;
            }

        }

        prev_pts = curr_pts;
        cout << players[index]->loser->get_name() << endl;
        index++;
        
    }

}


/*******************************************************************************
 ** Function: display_list
 ** Description: Prints values for all nodes in StackList
 ** Parameters: None
 ******************************************************************************/

  void StackList::display_list() const {
    StackNode* node_ptr = head;

    while (node_ptr) {
        cout << node_ptr->loser->get_name() << endl;
        node_ptr = node_ptr->next;
    }

    cout << endl << endl;
}


/*******************************************************************************
 ** Function: ~StackList
 ** Description: Deconstructor; frees memory allocated for all nodes
 ** Parameters: None
 ******************************************************************************/

StackList::~StackList() {
    StackNode* node_ptr = head;

    while (node_ptr != NULL) {
        StackNode* garbage = node_ptr;
        node_ptr = node_ptr->next;
        delete garbage;
    }

}
