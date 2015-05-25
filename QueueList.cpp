/*******************************************************************************
 ** Program Filename: QueueList.cpp
 ** Author: Dennis Sloan
 ** Date: 05/15/15
 ** Description: Implementation of QueueList class methods:
 **              queue_add (adds node to QueueList)
 **              queue_remove (removes node from QueueList)
 **              display_list (displays QueueList)
 ******************************************************************************/


#include <iostream>
#include "QueueList.hpp"
#include "Character.hpp"

using namespace std;


bool QueueList::isEmpty() {
    if (head == NULL) {
       return true;
    }
    else {
       return false;
    }
}


/*******************************************************************************
 ** Function: queue_add
 ** Description: Adds node to QueueList
 ** Parameters: int num_in - value for node to be added
 ******************************************************************************/

void QueueList::queue_add(Character* char_in) {

    // If head does not exist, new node becomes head
    if (head == NULL) {
        head = new QueueNode(char_in);
    }
    // If head exists, new node is created with last node as "previous" node 
    else {
        QueueNode* node_ptr = head;

        while (node_ptr->next != NULL) {
            node_ptr = node_ptr->next; 
        }
      
        node_ptr->next = new QueueNode(char_in, node_ptr);
     }

}


/*******************************************************************************
 ** Function: queue_remove
 ** Description: Removes node to QueueList
 ** Parameters: int num_out - value for node to be removed
 ******************************************************************************/

Character* QueueList::queue_remove() {

    Character* ret_char;

    QueueNode* node_ptr; // Stores node being worked with
    QueueNode* prev_node_ptr; // Stores previous node to node_ptr

    // If there is no head, list is empty - nothing to be removed
    if (!head) {
       return NULL;
    }

    else {
        ret_char = head->fighter;
        node_ptr = head;
        head = head->next;
        delete node_ptr;
        return ret_char;
    }

}


/*******************************************************************************
 ** Function: display_list
 ** Description: Prints value of name variable for each node in QueueList
 ** Parameters: None
 ******************************************************************************/

void QueueList::display_list() const {
    QueueNode* node_ptr = head;

    while (node_ptr) {
        cout << node_ptr->fighter->get_name() << endl;
        node_ptr = node_ptr->next;
    }

    cout << endl;
}


/*******************************************************************************
 ** Function: ~QueueList
 ** Description: Destructor; freems memory allocated for all nodes
 ** Parameters: None
 ******************************************************************************/

QueueList::~QueueList() {
    QueueNode* node_ptr = head;

    while (node_ptr != NULL) {
        QueueNode* garbage = node_ptr;
        node_ptr = node_ptr->next;
        delete garbage;
    }

}


/* 
 * Set and get team_pts methods - specific to game
 */

void QueueList::set_team_pts(int pts_in) {
    team_pts += pts_in;
}


int QueueList::get_team_pts() {
    return team_pts;
}
