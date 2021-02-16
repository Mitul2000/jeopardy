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
#include "questions.h"


// Initializes the array of questions for the game
struct question {

	char answer[50];
	char category[7];
	char question[100];
	int value;
	bool answered;
};
struct question jeopardyQues[16];


void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    	strcpy(jeopardyQues[0].category, "History");
	strcpy(jeopardyQues[0].question, "What year did World War II end?");
	strcpy(jeopardyQues[0].answer, "1945");
	jeopardyQues[0].value = 100;
	jeopardyQues[0].answered = false;

	strcpy(jeopardyQues[1].category, "History");
	strcpy(jeopardyQues[1].question, "What year did World War I end?");
	strcpy(jeopardyQues[1].answer, "1918");
	jeopardyQues[1].value = 200;
	jeopardyQues[1].answered = false;

	strcpy(jeopardyQues[2].category, "History");
	strcpy(jeopardyQues[2].question, "What year was the atomic bomb detonated in Hiroshima?");
	strcpy(jeopardyQues[2].answer, "1945");
	jeopardyQues[2].value = 300;
	jeopardyQues[2].answered = false;

	strcpy(jeopardyQues[3].category, "History");
	strcpy(jeopardyQues[3].question, "Who was the first president of United States of America?");
	strcpy(jeopardyQues[3].answer, "George Washington");
	jeopardyQues[3].value = 400;
	jeopardyQues[3].answered = false;

	strcpy(jeopardyQues[4].category, "Science");
	strcpy(jeopardyQues[4].question, "What is the chemical formula of water?");
	strcpy(jeopardyQues[4].answer, "H20");
	jeopardyQues[4].value = 100;
	jeopardyQues[4].answered = false;

	strcpy(jeopardyQues[5].category, "Science");
	strcpy(jeopardyQues[5].question, "What is the largest blood vessel in the body?");
	strcpy(jeopardyQues[5].answer, "Aorta");
	jeopardyQues[5].value = 200;
	jeopardyQues[5].answered = false;

	strcpy(jeopardyQues[6].category, "Science");
	strcpy(jeopardyQues[6].question, "What does Na stand for on the periodic table?");
	strcpy(jeopardyQues[6].answer, "Sodium");
	jeopardyQues[6].value = 300;
	jeopardyQues[6].answered = false;

	strcpy(jeopardyQues[7].category, "Science");
	strcpy(jeopardyQues[7].question, "What is the smallest structural and functional unit of an organism?");
	strcpy(jeopardyQues[7].answer, "A cell");
	jeopardyQues[7].value = 400;
	jeopardyQues[7].answered = false;

	strcpy(jeopardyQues[8].category, "Animals");
	strcpy(jeopardyQues[8].question, "Which animal can run the fastest?");
	strcpy(jeopardyQues[8].answer, "Cheetah");
	jeopardyQues[8].value = 100;
	jeopardyQues[8].answered = false;

	strcpy(jeopardyQues[9].category, "Animals");
	strcpy(jeopardyQues[9].question, "What is the largest bird?");
	strcpy(jeopardyQues[9].answer, "Ostrich");
	jeopardyQues[9].value = 200;
	jeopardyQues[9].answered = false;

	strcpy(jeopardyQues[10].category, "Animals");
	strcpy(jeopardyQues[10].question, "what is the largest mammal in the world?");
	strcpy(jeopardyQues[10].answer, "Blue whale");
	jeopardyQues[10].value = 300;
	jeopardyQues[10].answered = false;

	strcpy(jeopardyQues[11].category, "Animals");
	strcpy(jeopardyQues[11].question, "Which animal has the strongest bit force?");
	strcpy(jeopardyQues[11].answer, "Crocodile");
	jeopardyQues[11].value = 400;
	jeopardyQues[11].answered = false;

	strcpy(jeopardyQues[12].category, "Geography");
	strcpy(jeopardyQues[12].question, "In what continent is Malaysia located?");
	strcpy(jeopardyQues[12].answer, "Asia");
	jeopardyQues[12].value = 100;
	jeopardyQues[12].answered = false;

	strcpy(jeopardyQues[13].category, "Geography");
	strcpy(jeopardyQues[13].question, "Kampala is the capital of what country?");
	strcpy(jeopardyQues[13].answer, "Uganada");
	jeopardyQues[13].value = 200;
	jeopardyQues[13].answered = false;

	strcpy(jeopardyQues[14].category, "Geography");
	strcpy(jeopardyQues[14].question, "In what country are the Stonehenges located?");
	strcpy(jeopardyQues[14].answer, "United Kingdom");
	jeopardyQues[14].value = 300;
	jeopardyQues[14].answered = false;

	strcpy(jeopardyQues[15].category, "Geography");
	strcpy(jeopardyQues[15].question, "In what country are the Angel Falls located?");
	strcpy(jeopardyQues[15].answer, "Venezuela");
	jeopardyQues[15].value = 400;
	jeopardyQues[15].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for(int i = 0; i<16; i = i + 1){
    if (jeopardyQues[i].answered == false){
	printf("Category: %s, Value: %d\n", jeopardyQues[i].category, jeopardyQues[i].value);
		}
	}
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	for (int i = 0; i < 16; i = i + 1){
	if (strcmp(jeopardyQues[i].category, category)==0 && jeopardyQues[i].value == value){
		printf("%s\n", jeopardyQues[i].question);
		
		}
	}
	
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for (int i = 0; i < 16; i = i + 1){
	if (strcmp(jeopardyQues[i].category, category)==0 && jeopardyQues[i].value == value && strcmp(jeopardyQues[i].answer,answer) == 0){
		jeopardyQues[i].answered = true;
		return true;
		}
	}
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    	for (int i = 0; i < 16; i = i + 1){
	if (strcmp(jeopardyQues[i].category, category)==0 && jeopardyQues[i].value == value && jeopardyQues[i].answered == true){
		return true;
		}
	}
    return false;
}

// Returns true if all questions answered
bool all_answered()
{
    // lookup the question and see if it's already been marked as answered
		for (int i = 0; i < 16; i++)
		{
			if (jeopardyQues[i].answered == false)
			{
				return false;
			}
		}
		return true;
}

bool validquestion(char *category, int value){
	for (int i = 0; i < 16; i = i + 1){
	if (strcmp(jeopardyQues[i].category, category)==0 && jeopardyQues[i].value == value){
		return true;
		}
	}
	return false;
}


