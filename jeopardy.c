/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Milan, Ashad, Rodaba>
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
char currentAnswer[50];
char *tokens[2] = {"what is ","who is "};
char currentName[50];
int playerTurn;
char currentCategory[10];
int currentDollarValue;

void delete(char string[], char substr[])
{
	int i = 0;
	int string_length = strlen(string);
	int substr_length = strlen(substr);
	while (i < string_length)
	{
		if (strstr(&string[i], substr) == &string[i])
		{
			string_length -= substr_length;
			for (int j = i; j < string_length; j++)
				string[j] = string[j + substr_length];
		}
   		else i++;
  	}
  	string[i] = '\0';
}

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens)
{
	if(strstr(input,tokens[0]))
	{
		delete(input,tokens[0]);
		strcpy(currentAnswer,input);
	}
	if(strstr(input,tokens[1]))
	{
		delete(input,tokens[1]);
		strcpy(currentAnswer,input);
	}
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players)
{
	struct player temp;
	for(int i = 0; i < num_players; ++i)
	{
		for (int j = i+1; j < num_players; ++j)
		{
			if (players[i].score < players[j].score)
			{
			
				temp=players[i];
				players[i]=players[j];
				players[j]=temp;
			}
		}
	}
	
	printf("\n\n---Game Results---");
	printf("\n1st place ($%d): %s",players[0].score,players[0].name);
	printf("\n2nd place ($%d): %s",players[1].score,players[1].name);
	printf("\n3rd place ($%d): %s",players[2].score,players[2].name);
	printf("\n4th place ($%d): %s",players[3].score,players[3].name);
}


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    printf("\nWelcome to our jeopardy game!\n");
    initialize_game();

    // Prompt for players names and initialize each of the players in the array
    
    printf("\nPlease enter unique names!\n");
    
    printf("\nPlayer 1: ");
    scanf("%s",currentName);
    strcpy(players[0].name,currentName);
    players[0].score = 0;
    
    printf("\nPlayer 2: ");
    scanf("%s",currentName);
    strcpy(players[1].name,currentName);
    players[1].score = 0;
    
    printf("\nPlayer 3: ");
    scanf("%s",currentName);
    strcpy(players[2].name,currentName);
    players[2].score = 0;
    
    printf("\nPlayer 4: ");
    scanf("%s",currentName);
    strcpy(players[3].name,currentName);
    players[3].score = 0;

    playerTurn = 1;

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        
        if(playerTurn == 1 && !finished())
        {
        	display_categories();
        	
        	printf("\nPlayer %d, choose an available category: ",playerTurn);
        	scanf("%s",currentCategory);
        	while((!category_exists(currentCategory)) || (already_answered(currentCategory,100) && already_answered(currentCategory,200) && already_answered(currentCategory,300) && already_answered(currentCategory,400)))
        	{
        		printf("\nEnter a valid category: ");
        		scanf("%s",currentCategory);
        	}
        	
        	printf("\nChoose an available dollar value: ");
        	scanf("%d",&currentDollarValue);
        	while((currentDollarValue != 100 && currentDollarValue != 200 && currentDollarValue != 300 && currentDollarValue != 400) || already_answered(currentCategory,currentDollarValue))
        	{
        		printf("\nEnter a valid amount: ");
        		scanf("%d",&currentDollarValue);
        	}
        	
        	display_question(currentCategory,currentDollarValue);
        	
        	printf("\nYour answer: ");
        	scanf(" %[^\n]",currentAnswer);
        	while(!strstr(currentAnswer,tokens[0]) && !strstr(currentAnswer,tokens[1]))
        	{
        		printf("\nEnter a valid answer: ");
        		scanf(" %[^\n]",currentAnswer);
        	}
        	
        	tokenize(currentAnswer,tokens);
        	
        	if(valid_answer(currentCategory,currentDollarValue,currentAnswer))
        	{
        		printf("\nYour answer was correct!!! $%d has been added to your score!",currentDollarValue);
        		update_score(players,4,players[0].name,currentDollarValue);
        	}
        	else
        		printf("\nSorry, your answer was incorrect. Please pay attention to format, capitalization, and spelling.");
        	
        	playerTurn++;
        }
        if(playerTurn == 2 && !finished())
        {
        	display_categories();
        	
        	printf("\nPlayer %d, choose an available category: ",playerTurn);
        	scanf("%s",currentCategory);
        	while((!category_exists(currentCategory)) || (already_answered(currentCategory,100) && already_answered(currentCategory,200) && already_answered(currentCategory,300) && already_answered(currentCategory,400)))
        	{
        		printf("\nEnter a valid category: ");
        		scanf("%s",currentCategory);
        	}
        	
        	printf("\nChoose an available dollar value: ");
        	scanf("%d",&currentDollarValue);
        	while((currentDollarValue != 100 && currentDollarValue != 200 && currentDollarValue != 300 && currentDollarValue != 400) || already_answered(currentCategory,currentDollarValue))
        	{
        		printf("\nEnter a valid amount: ");
        		scanf("%d",&currentDollarValue);
        	}
        	
        	display_question(currentCategory,currentDollarValue);
        	
        	printf("\nYour answer: ");
        	scanf(" %[^\n]",currentAnswer);
        	while(!strstr(currentAnswer,tokens[0]) && !strstr(currentAnswer,tokens[1]))
        	{
        		printf("\nEnter a valid answer: ");
        		scanf(" %[^\n]",currentAnswer);
        	}
        	
        	tokenize(currentAnswer,tokens);
        	
        	if(valid_answer(currentCategory,currentDollarValue,currentAnswer))
        	{
        		printf("\nYour answer was correct!!! $%d has been added to your score!",currentDollarValue);
        		update_score(players,4,players[1].name,currentDollarValue);
        	}
        	else
        		printf("\nSorry, your answer was incorrect. Please pay attention to format, capitalization, and spelling.");
        	
        	playerTurn++;
        }
        if(playerTurn == 3 && !finished())
        {
        	display_categories();
        	
        	printf("\nPlayer %d, choose an available category: ",playerTurn);
        	scanf("%s",currentCategory);
        	while((!category_exists(currentCategory)) || (already_answered(currentCategory,100) && already_answered(currentCategory,200) && already_answered(currentCategory,300) && already_answered(currentCategory,400)))
        	{
        		printf("\nEnter a valid category: ");
        		scanf("%s",currentCategory);
        	}
        	
        	printf("\nChoose an available dollar value: ");
        	scanf("%d",&currentDollarValue);
        	while((currentDollarValue != 100 && currentDollarValue != 200 && currentDollarValue != 300 && currentDollarValue != 400) || already_answered(currentCategory,currentDollarValue))
        	{
        		printf("\nEnter a valid amount: ");
        		scanf("%d",&currentDollarValue);
        	}
        	
        	display_question(currentCategory,currentDollarValue);
        	
        	printf("\nYour answer: ");
        	scanf(" %[^\n]",currentAnswer);
        	while(!strstr(currentAnswer,tokens[0]) && !strstr(currentAnswer,tokens[1]))
        	{
        		printf("\nEnter a valid answer: ");
        		scanf(" %[^\n]",currentAnswer);
        	}
        	
        	tokenize(currentAnswer,tokens);
        	
        	if(valid_answer(currentCategory,currentDollarValue,currentAnswer))
        	{
        		printf("\nYour answer was correct!!! $%d has been added to your score!",currentDollarValue);
        		update_score(players,4,players[2].name,currentDollarValue);
        	}
        	else
        		printf("\nSorry, your answer was incorrect. Please pay attention to format, capitalization, and spelling.");
        	
        	playerTurn++;
        }
        if(playerTurn == 4 && !finished())
        {
        	display_categories();
        	
        	printf("\nPlayer %d, choose an available category: ",playerTurn);
        	scanf("%s",currentCategory);
        	while((!category_exists(currentCategory)) || (already_answered(currentCategory,100) && already_answered(currentCategory,200) && already_answered(currentCategory,300) && already_answered(currentCategory,400)))
        	{
        		printf("\nEnter a valid category: ");
        		scanf("%s",currentCategory);
        	}
        	
        	printf("\nChoose an available dollar value: ");
        	scanf("%d",&currentDollarValue);
        	while((currentDollarValue != 100 && currentDollarValue != 200 && currentDollarValue != 300 && currentDollarValue != 400) || already_answered(currentCategory,currentDollarValue))
        	{
        		printf("\nEnter a valid amount: ");
        		scanf("%d",&currentDollarValue);
        	}
        	
        	display_question(currentCategory,currentDollarValue);
        	
        	printf("\nYour answer: ");
        	scanf(" %[^\n]",currentAnswer);
        	while(!strstr(currentAnswer,tokens[0]) && !strstr(currentAnswer,tokens[1]))
        	{
        		printf("\nEnter a valid answer: ");
        		scanf(" %[^\n]",currentAnswer);
        	}
        	
        	tokenize(currentAnswer,tokens);
        	
        	if(valid_answer(currentCategory,currentDollarValue,currentAnswer))
        	{
        		printf("\nYour answer was correct!!! $%d has been added to your score!",currentDollarValue);
        		update_score(players,4,players[3].name,currentDollarValue);
        	}
        	else
        		printf("\nSorry, your answer was incorrect. Please pay attention to format, capitalization, and spelling.");
        	
        	playerTurn = 1;
        }
        
        if(finished())
        {
        	show_results(players,4);
        	break;
        }

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
