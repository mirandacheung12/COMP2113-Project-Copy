#ifndef MINI_GAME_H
#define MINI_GAME_H

#include "player.h"
#include "inventory.h"
#include <iostream>
#include <string>

using namespace std;

// Function declarations
void minigame_menu();            // Display menu
void ChooseMiniGame(Player &player);		 // User choosing the game
bool playNumberGuessGame();    // Deckaratuib for Number Guess Game
bool playMathGame();           // Declaration for Math Game
bool playRPSGame();            // Declaration for Rock-Paper-Scissors Game
bool playWordScrambleGame();   // Declaration for Word Scramble Game

#endif // MINI_GAME_H
