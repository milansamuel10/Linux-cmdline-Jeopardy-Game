/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2022, <Milan, Rodaba, Ashad>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"

/*char categories[4][10] = {"Geography","History","Science","Sports"};

typedef struct Question
{
	char category[10];
	char question[100];
	char answer[50];
	int value;
	bool answered;
	
	char cellToString[5];
} Question;

struct Question questions[16];*/

// Initializes the array of questions for the game
void initialize_game(void)
{
     // initialize each question struct and assign it to the questions array
    
    strcpy(questions[0].category,"Geography");
    strcpy(questions[0].question,"Which country has the highest population?");
    strcpy(questions[0].answer,"China");
    questions[0].value = 100;
    questions[0].answered = false;
    strcpy(questions[0].cellToString,"$100");
    
    strcpy(questions[1].category,"Geography");
    strcpy(questions[1].question,"Which is the latitude that runs through the centre of the Earth?");
    strcpy(questions[1].answer,"Equator");
    questions[1].value = 200;
    questions[0].answered = false;
    strcpy(questions[1].cellToString,"$200");
    
    strcpy(questions[2].category,"Geography");
    strcpy(questions[2].question,"Which is the longest river in the world?");
    strcpy(questions[2].answer,"The Nile");
    questions[2].value = 300;
    questions[0].answered = false;
    strcpy(questions[2].cellToString,"$300");
    
    strcpy(questions[3].category,"Geography");
    strcpy(questions[3].question,"Which is the largest waterfall in the world?");
    strcpy(questions[3].answer,"Victoria Falls");
    questions[3].value = 400;
    questions[0].answered = false;
    strcpy(questions[3].cellToString,"$400");
    
    
    strcpy(questions[4].category,"History");
    strcpy(questions[4].question,"Who was the first man on the moon?");
    strcpy(questions[4].answer,"Neil Armstrong");
    questions[4].value = 100;
    questions[0].answered = false;
    strcpy(questions[4].cellToString,"$100");
    
    strcpy(questions[5].category,"History");
    strcpy(questions[5].question,"The Olympic Games originated from which country?");
    strcpy(questions[5].answer,"Greece");
    questions[5].value = 200;
    questions[0].answered = false;
    strcpy(questions[5].cellToString,"$200");
    
    strcpy(questions[6].category,"History");
    strcpy(questions[6].question,"The iconic “I Have a Dream” speech was delivered by?");
    strcpy(questions[6].answer,"Martin Luther King");
    questions[6].value = 300;
    questions[0].answered = false;
    strcpy(questions[6].cellToString,"$300");
    
    strcpy(questions[7].category,"History");
    strcpy(questions[7].question,"Henry the Eighth had how many wives?");
    strcpy(questions[7].answer,"6");
    questions[7].value = 400;
    questions[0].answered = false;
    strcpy(questions[7].cellToString,"$400");
    
    
    strcpy(questions[8].category,"Science");
    strcpy(questions[8].question,"What is the gas essential for us to breathe?");
    strcpy(questions[8].answer,"Oxygen");
    questions[8].value = 100;
    questions[0].answered = false;
    strcpy(questions[8].cellToString,"$100");
    
    strcpy(questions[9].category,"Science");
    strcpy(questions[9].question,"What is the nearest planet to the Sun?");
    strcpy(questions[9].answer,"Mercury");
    questions[9].value = 200;
    questions[0].answered = false;
    strcpy(questions[9].cellToString,"$200");
    
    strcpy(questions[10].category,"Science");
    strcpy(questions[10].question,"What is the freezing point of water?");
    strcpy(questions[10].answer,"0 degrees Celsius");
    questions[10].value = 300;
    questions[0].answered = false;
    strcpy(questions[10].cellToString,"$300");
    
    strcpy(questions[11].category,"Science");
    strcpy(questions[11].question,"Nucleons are made up of neutrons and ...?");
    strcpy(questions[11].answer,"Protons");
    questions[11].value = 400;
    questions[0].answered = false;
    strcpy(questions[11].cellToString,"$400");
    
    
    strcpy(questions[12].category,"Sports");
    strcpy(questions[12].question,"What does NBA stand for?");
    strcpy(questions[12].answer,"National Basketball Association");
    questions[12].value = 100;
    questions[0].answered = false;
    strcpy(questions[12].cellToString,"$100");
    
    strcpy(questions[13].category,"Sports");
    strcpy(questions[13].question,"In which sport was Muhammad Ali popular?");
    strcpy(questions[13].answer,"Boxing");
    questions[13].value = 200;
    questions[0].answered = false;
    strcpy(questions[13].cellToString,"$200");
    
    strcpy(questions[14].category,"Sports");
    strcpy(questions[14].question,"How many bases are there on a baseball field?");
    strcpy(questions[14].answer,"4");
    questions[14].value = 300;
    questions[0].answered = false;
    strcpy(questions[14].cellToString,"$300");
    
    strcpy(questions[15].category,"Sports");
    strcpy(questions[15].question,"What color are the goal posts in American football?");
    strcpy(questions[15].answer,"Yellow");
    questions[15].value = 400;
    questions[0].answered = false;
    strcpy(questions[15].cellToString,"$400");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    
    printf("\n\n|  Geography |   History  |  Science   |   Sports   |\n");
    printf("-----------------------------------------------------\n");
    printf("|    %s    |    %s    |    %s    |    %s    |\n", questions[0].cellToString, questions[4].cellToString, questions[8].cellToString, questions[12].cellToString);
    printf("-----------------------------------------------------\n");
    printf("|    %s    |    %s    |    %s    |    %s    |\n", questions[1].cellToString, questions[5].cellToString, questions[9].cellToString, questions[13].cellToString);
    printf("-----------------------------------------------------\n");
    printf("|    %s    |    %s    |    %s    |    %s    |\n", questions[2].cellToString, questions[6].cellToString, questions[10].cellToString, questions[14].cellToString);
    printf("-----------------------------------------------------\n");
    printf("|    %s    |    %s    |    %s    |    %s    |\n", questions[3].cellToString, questions[7].cellToString, questions[11].cellToString, questions[15].cellToString);
    printf("-----------------------------------------------------\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	if(strcmp(category,categories[0]) == 0)
	{
		for(int i = 0; i < 4; i++)
		{
			if(questions[i].value == value)
				printf("\nQuestion: %s\n",questions[i].question);
		}
	}
	
	else if(strcmp(category,categories[1]) == 0)
	{
		for(int i = 4; i < 8; i++)
		{
			if(questions[i].value == value)
				printf("\nQuestion: %s\n",questions[i].question);
		}
	}
	
	else if(strcmp(category,categories[2]) == 0)
	{
		for(int i = 8; i < 12; i++)
		{
			if(questions[i].value == value)
				printf("\nQuestion: %s\n",questions[i].question);
		}
	}
	
	else if(strcmp(category,categories[3]) == 0)
	{
		for(int i = 12; i < 16; i++)
		{
			if(questions[i].value == value)
				printf("\nQuestion: %s\n",questions[i].question);
		}
	}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{	
	// Look into string comparison functions
	
	if(strcmp(category,categories[0]) == 0)
	{
		for(int i = 0; i < 4; i++)
		{
			if(questions[i].value == value)
			{
				questions[i].answered = true;
				strcpy(questions[i].cellToString,"----");
				
				if(strstr(answer,questions[i].answer))
					return true;
			}
		}
	}
	
	else if(strcmp(category,categories[1]) == 0)
	{
		for(int i = 4; i < 8; i++)
		{
			if(questions[i].value == value)
			{
				questions[i].answered = true;
				strcpy(questions[i].cellToString,"----");
				
				if(strstr(answer,questions[i].answer))
					return true;
			}
		}
	}
	
	else if(strcmp(category,categories[2]) == 0)
	{
		for(int i = 8; i < 12; i++)
		{
			if(questions[i].value == value)
			{
				questions[i].answered = true;
				strcpy(questions[i].cellToString,"----");
				
				if(strstr(answer,questions[i].answer))
					return true;
			}
		}
	}
	
	else if(strcmp(category,categories[3]) == 0)
	{
		for(int i = 12; i < 16; i++)
		{
			if(questions[i].value == value)
			{
				questions[i].answered = true;
				strcpy(questions[i].cellToString,"----");
				
				if(strstr(answer,questions[i].answer))
					return true;
			}
		}
	}
	
	return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
	// lookup the question and see if it's already been marked as answered
	
	if(strcmp(category,categories[0]) == 0)
	{
		for(int i = 0; i < 4; i++)
		{
			if(questions[i].value == value && questions[i].answered == true)
				return true;
		}
	}
	
	else if(strcmp(category,categories[1]) == 0)
	{
		for(int i = 4; i < 8; i++)
		{
			if(questions[i].value == value && questions[i].answered == true)
				return true;
		}
	}
	
	else if(strcmp(category,categories[2]) == 0)
	{
		for(int i = 8; i < 12; i++)
		{
			if(questions[i].value == value && questions[i].answered == true)
				return true;
		}
	}
	
	else if(strcmp(category,categories[3]) == 0)
	{
		for(int i = 12; i < 16; i++)
		{
			if(questions[i].value == value && questions[i].answered == true)
				return true;
		}
	}
	
	return false;
}

bool category_exists(char *input)
{
    for(int i = 0; i < NUM_CATEGORIES; i++)
    {
    	if(strstr(input,categories[i]))
    		return true;
    }
    
    return false;
}

bool finished(void)
{
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		if(questions[i].answered == false)
			return false;
	}
	
	return true;
}
