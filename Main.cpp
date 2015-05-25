/*******************************************************************************
 ** Program Filename: Main.cpp
 ** Author: Dennis Sloan
 ** Date: 05/18/15
 ** Description: This file contains the main method that tests the combat
 **              hierarchy. It is user-driven and includes some validation.
 ******************************************************************************/


#include <iostream>
#include <string>
#include "Character.hpp"
#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "BlueMen.hpp"
#include "Shadow.hpp"
#include "Dice.hpp"
#include "QueueList.hpp"
#include "StackList.hpp"

using namespace std;


/******************************************************************************* ** Function: print_attack_stats
 ** Description: Prints players' strength points after each attack
 ** Parameters: Character* player1, Character* player2: pointers to 
 **             active attacker and defender
 ******************************************************************************/

void print_attack_stats(Character* player1, Character* player2) {
    cout << "New strength points: " << endl;
    cout << player1->get_name() << ": " << player1->get_strength_pts()
         << endl;
    cout << player2->get_name() << ": " << player2->get_strength_pts()
         << endl;
}


/******************************************************************************* ** Function: print_round_intro
 ** Description: Introduces each round:
 **              Prints names of attacker and defender
 **              Prints names of fighters waiting in team queues
 ** Parameters: Character* player1, Character* player 2: active players
                QueueList* team1, Queuelist* team2: Queues for each team
 ******************************************************************************/

void print_round_intro(Character* player1, Character* player2,
                       QueueList* team1, QueueList* team2) {

   cout << "\n\nCurrently fighting: " << player1->get_name() << " v. "
        << player2->get_name() << endl;
           cout << "Waiting in Team 1 Lineup: " << endl;
           team1->display_list();
           cout << "Waiting in Team 2 Lineup: " << endl;
           team2->display_list();
}


/******************************************************************************* ** Function: end_round
 ** Description: Prints winner of round
 **              Moves losing player to retire_pile StackList
 **              Sets tourn_pts for winner
 **              Calls heal function on winner
 **              Moves winner to end of team's queue
 ** Parameters: Character* winner, Character* loser: winning/losing fighters
 **             QueueList* win_team: Winner's team
 **             StackList* retire_pile: Holds characters finished fighting. 
 ******************************************************************************/

void end_round(Character* winner, Character* loser, QueueList* win_team,
               StackList* retire_pile) {
  
    cout << winner->get_name() << " wins this round!" << endl;
    retire_pile->stack_add(loser);
    winner->set_tourn_pts(1);
    win_team->set_team_pts(1);
    winner->heal();
    win_team->queue_add(winner);

}


/******************************************************************************* ** Function: print_rd_results
 ** Description: Prints end of round standings:
 **              Fighting players' tourn_pts values
 **              Teams' total tournament points (team_pts)
 ** Parameters: Character* player1, Character* player2: active players
 **             QueueList* team1, QueueList* team2: team lists 
 ******************************************************************************/

void print_rd_results(Character* player1, Character* player2,
                     QueueList* team1, QueueList* team2) {

    cout << "\nEnd of Round Standings:" << endl;
    cout << player1->get_name() << " tournament pts: "
         << player1->get_tourn_pts() << endl;
    cout << player2->get_name() << " tournament pts: "
         << player2->get_tourn_pts() << endl;
    cout << "Team 1 tournament pts: " << team1->get_team_pts() << endl;
    cout << "Team 2 tournament pts: " << team2->get_team_pts() << endl << endl;

}


int main () {

    int num_chars = 0;
    int counter = 0;
    int team = 0;
    int player_choice = 0;
    string player_name = " ";
    
    QueueList team1;
    QueueList team2;
    StackList retire_pile;

    Character* player1;
    Character* player2;

    // Introduction to game
    cout << "\nThis is a fantasy combat tournament. You will choose two teams "
         << "of Characters " << endl;
    cout << "to combat one another.  In each round, two characters will fight "
         << "to the death." << endl;  
    cout << "Rounds will continue until only one character remains standing.  "
         << endl;

    cout << "\nFor each round, 1 point will be be awarded to each winning "
         << "Character and " << endl;
    cout << "1 point will be award to its team.  As each winning character "
         << "returns to its" << endl;
    cout << "team's lineup, 1 strength_point will be restored." << endl;

    cout << "The winning team will have the most points at the end of all "
         << "rounds." << endl; 
    cout << "\n1st, 2nd, and 3rd place will be awarded to characters "
         << "based on total " << endl;
    cout << "number of pts." << endl;

    // Get number of players per team from user
    cout << "\nHow many characters should be on each team? "
         << "(Enter a positive integer) ";
    cin >> num_chars;
    counter = num_chars; // Will count down while naming characters

    //Set current team to 1
    team = 1;

    /*
     * Name characters for each team
     * Loops through as counter coutns down for each team
     * After team 1 is finished, counter reset for team 2
     */ 
    while (counter > 0) {
        
        cout << "\n" << counter << " slot(s) to fill for Team ";
        if (team == 1) {
            cout << "1.  ";
        }
        else if (team == 2) {
            cout << "2.  "; 
        }
        cout << "Choose from the following:" << endl;
        cout << "1 - Goblin" << endl;
        cout << "2 - Barbarian" << endl;
        cout << "3 - Reptile People" << endl;
        cout << "4 - Blue Men" << endl;
        cout << "5 - The Shadow" << endl;
        cout << "Enter a number option: ";
        cin >> player_choice; 
        cout << "Enter a name for this character: ";
        cin >> player_name;
        cout << endl;

        /* 
         * Create appropriate object for each player
         * Add player to appropriateteam QueueList
         */  
        if (player_choice == 1) {
            Goblin gob(player_name);
            if (team == 1) {  
                team1.queue_add(new Goblin(player_name));
           }
            else {
                team2.queue_add(new Goblin(player_name));
            }
        }
        else if (player_choice == 2) {
            if (team == 1) {  
                team1.queue_add(new Barbarian(player_name));
            }
            else {
                team2.queue_add(new Barbarian(player_name));
            }
        }
        else if (player_choice == 3) {
            if (team == 1) {  
                team1.queue_add(new Reptile(player_name));
            }
            else {
                team2.queue_add(new Reptile(player_name));
            }
        }
        else if (player_choice == 4) {
            if (team == 1) {  
                team1.queue_add(new BlueMen(player_name));
            }
            else {
                team2.queue_add(new BlueMen(player_name));
            }
        }
        else if (player_choice == 5) {
            if (team == 1) {  
                team1.queue_add(new Shadow(player_name));
            }
            else {
                team2.queue_add(new Shadow(player_name));
            }
 
        }

        counter--;
        
        // Switch teams when team 1 is fully named and created
        if (team == 1 && counter == 0) {
            team = 2;
            counter = num_chars;
        }

    } 

    // Print team rosters
    cout << "Team 1:" << endl;
    team1.display_list();
    cout << "Team 2:" << endl;
    team2.display_list();

    // Run tournament rounds until one team runs out of players 
    while (!team1.isEmpty() && !team2.isEmpty()) { 

        // Remove a player from each team's queueList
        player1 = team1.queue_remove();
        player2 = team2.queue_remove();

        do {
            // Introduce round of combat
            print_round_intro(player1, player2, &team1, &team2);
            cout << player1->get_name() << " attacks " << player2->get_name()
                 << "!" << endl;

            // Initiate & print attack
            player2->defend(player1);
            print_attack_stats(player1, player2);

            // Initiate and print next attack if no one has lost
            if (player2->get_strength_pts() > 0) {
                print_round_intro(player1, player2, &team1, &team2);

                cout << player2->get_name() << " attacks " 
                     << player1->get_name()
                     << "!" << endl;
                player1->defend(player2);
                print_attack_stats(player1, player2);

            }

            cout << endl;

            // If either player is out of strength points, call end_round 
            if (player1->get_strength_pts() <= 0) {
                end_round(player2, player1, &team2, &retire_pile);
                print_rd_results(player1, player2, &team1, &team2); 
            }
            else if (player2->get_strength_pts() <= 0) {
                end_round(player1, player2, &team1, &retire_pile);
                print_rd_results(player1, player2, &team1, &team2);
            }


        } while (player1->get_strength_pts() > 0 &&
                     player2->get_strength_pts() > 0);

    }

        /*
         * Check for any fighters left in queue's after battle
         * Move all players to retire_pile for sorting and placing
         */  
        while (!team1.isEmpty() || !team2.isEmpty()) {
            if (!team1.isEmpty()) {
                player1 = team1.queue_remove();
                retire_pile.stack_add(player1);
            }
            if (!team2.isEmpty()) {
                player2 = team2.queue_remove();
                retire_pile.stack_add(player2);
            }
        }
    
    // Print final standings
    cout << "Final Team Standings:" << endl;
    cout << "Team 1 total points: " << team1.get_team_pts() << endl;
    cout << "Team 2 total points: " << team2.get_team_pts() << endl; 
    cout << "Winning Team: ";
    if (team1.get_team_pts() > team2.get_team_pts()) {
        cout << "TEAM 1" << endl;
    }
    else if (team2.get_team_pts() > team1.get_team_pts()) {
        cout << "TEAM 2" << endl;
    }
    else {
        cout << "TIE" << endl;
    }

    // Print finishers/placings
    retire_pile.get_finishers();

    cout << endl;
   
    return 0;

}



