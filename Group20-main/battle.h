#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include <string>
#include <iostream>

#include "player.h"

using namespace std;


// Struct for enemy skills
struct enemySkills {
    string enemySkillName; // Name of the enemy skill
    int enemySkillDamage; // Damage of the enemy skill
};

// Struct for Enemy
struct Enemy {
    int enemyHealth; // Health points of the enemy
    int enemyPower; // Attack power of the enemy
    string enemyName; // Name of the enemy
    vector<enemySkills> skills; // List of skills the enemy can use
};


// Function prototypes
string performAttack(Player &player, Enemy &enemy, bool useSkill); // Function to perform an attack
string battle_start(Player &player, Enemy &enemy, int stage, int level); // Function to start a battle
bool run_stage(vector<string>& LowLevelBossNames, vector<string>& MiddleLevelBossNames, vector<string>& FinalLevelBossNames, Enemy &enemy, Player &player); // Function to run a stage of the game
// Functions for stage one to final stage
// ----------------------------------
bool stage_one(Player &player);
bool stage_two(Player &player);
bool stage_three(Player &player);
bool stage_four(Player &player);
bool final_stage(Player &player);
// ----------------------------------
void Battle(Player &player, int &progress_level); // Main battle function for managing stages

#endif 
