/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U: Operating Systems
 *
 * Copyright (C) 2015, <Milan, Ashad, Rodaba>
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

// Player struct for each player
typedef struct player{
    char name[50];
    int score;
} player;

// Returns true if the player name matches one of the existing players
extern bool player_exists(player *players, int num_players, char *name);

// Go through the list of players and update the score for the 
// player given their name
extern void update_score(player *players, int num_players, char *name, int score);

#endif /* PLAYERS_H_ */
