#ifndef GAME_SAVE_H
#define GAME_SAVE_H

#include <string>
#include <vector>
#include "player.h" // Include the player.h header file

// Placeholder for the actual type of game data
struct Gamedata {
    std::string filename;
    int progression_level;
    Player player;
    // Add other game data fields as needed
};

extern string directory;

// Function declarations
void check_files(const string& directory);
void save_files(const Gamedata& current_game);
void load_files(Gamedata& gameData, const string& directory);
void delete_files(std::vector<std::string> &save_record);
string get_current_directory();

#endif // GAME_SAVE_H
