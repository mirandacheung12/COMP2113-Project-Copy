#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h" 
#include <vector>
#include <string>


using namespace std;

// Struct for Player to store player attributes
struct Player {
    string playerName; // player name
    int playerHealth; // player health
    int playerPower; // player power 
    int playerMaxHealth; // player max health
    int playerExp; // player experience points
    int playerMaxExp; // player max experience points
    int playerLevel; // player level
    Inventory inventory; // player inventory
    vector <string> playerSkills; // player skills
};

#endif // PLAYER_H
