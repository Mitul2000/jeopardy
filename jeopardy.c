/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP 9 Mitul Patel, Raj Parikh, Preet Patel>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
char ans[100];


// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Enter Player 1 name\n");
    scanf("%s", players[0].name);
    players[0].score = 0;
    
    printf("Enter Player 2 name\n");
    scanf("%s", players[1].name);
    players[1].score = 0;

    printf("Enter Player 3 name\n");
    scanf("%s", players[2].name);
    players[2].score = 0;

    printf("Enter Player 4 name\n");
    scanf("%s", players[3].name);
    players[3].score = 0;
    
    // initialize each of the players in the array
	char uinput[100];
	char name[100];
  	char category[100];
  	int value = 0;
  	char* answer;
	
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
 		
        // Execute the game until all questions are answered
         printf("Who is choosing the question?\n");
    	 scanf("%s", name);
    	 
    	 if(player_exists(players, NUM_PLAYERS, name)){
    	 
	    	 display_categories();
		 printf("Select Category and Value\n");
		 scanf("%s", category);
		 scanf("%d", &value);
		 
		 if(validquestion(category, value)){
		 
		 	display_question(category, value);
			if(!already_answered(category, value)){
		 	 	printf("Enter you answer\n");
		  		scanf("%s", uinput);
		  		tokenize(uinput, ans);
		  
		  		if(valid_answer(category, value, ans)){
		   	 		printf("Correct\n");
		    			update_score(players, NUM_PLAYERS, name, value);
		  		}	
	      			else{
		    			printf("Incorrect Answer\n");
		  		}
			}
		 	 else{
		  		printf("Question already answered\n");
			}
		 
		 }
		 else{
		 	printf("Invalid category or value\n");
		 }     
         }
         else{
         printf("invalid name, try again\n");
         }
         // Display the final results and exit
    	
    	 if(all_answered()){
      		show_results(players, NUM_PLAYERS);
		break;
    	}
    }
    
    return EXIT_SUCCESS;
}

//function call to show the result
void show_results(player *players, int num_players){
  int winner = 0;
  int second = 0;
  int third = 0;
  int last = 0;
  for(int i = 0; i < num_players; i++){
    if(players[i].score > players[winner].score){
      winner = i;
    }
  }
  printf("Winner is %s with %d\n",players[winner].name, players[winner].score);
  players[winner].score = 0;

  for(int i = 0; i < num_players; i++){
    if(i != winner && players[i].score >= players[second].score){
      second = i;
    }
  }

  printf("Second is %s with %d\n",players[second].name, players[second].score);
  players[second].score = 0;  

  for(int i = 0; i < num_players; i++){
    if(i != winner && i != second && players[i].score >= players[third].score){
      third = i;
    }
  }

  printf("Third is %s with %d\n",players[third].name, players[third].score);
  players[third].score = 0;

  for(int i = 0; i < num_players; i++){
    if(i != winner && i != second && i != third){
      last = i;
    }
  }

  printf("Last is %s with %d\n",players[last].name, players[last].score);

  return;
}

//tokenize funciton 
void tokenize(char *input, char **tokens)
{
	char *token;
token = strtok(input, " ");
        int i = 0;
        while( token != NULL ) {

            if(i==2){
                strcpy(ans, token);
            }
            i++;
            token = strtok(NULL, " ");
	}

}



