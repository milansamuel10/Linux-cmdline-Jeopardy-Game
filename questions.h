/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define NUM_CATEGORIES 4
// The number of questions, you can use this in your functions in
// questions.c, this can be accessed in questions.c
#define NUM_QUESTIONS 16

// List of 3 categories as array of strings
static char categories[NUM_CATEGORIES][10] = {
    "Geography", 
    "History", 
    "Science",
    "Sports"
};

// Questions struct for each question
typedef struct question{
    char category[10];
    char question[100];
    char answer[50];
    int value;
    bool answered;
    
    char cellToString[5];
} question;

// An array of 12 questions (4 for each category), initialized in initialize_game
// this may need to be a pointer if you want it set dynamically
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
extern void initialize_game(void);

// Displays each of the remaining categories and question dollar values that have not been answered
extern void display_categories(void);

// Displays the question for the category and dollar value
extern void display_question(char *category, int value);

// Returns true if the answer is correct for the question for that category and dollar value
extern bool valid_answer(char *category, int value, char *answer);

// Returns true if the question has already been answered
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */
