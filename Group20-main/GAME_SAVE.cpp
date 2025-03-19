#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "GAME_SAVE.h"
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
using namespace std;


string directory;
// Function to get current directory
// Input: None, Output: current working directory
string get_current_directory() {
    char cwd[PATH_MAX]; // Buffer for the current directory path
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        return string(cwd); // Convert char array to std::string
    } else {
        perror("Error getting current directory");
        return ""; // Return an empty string on error
    }
}
// Function to show what save files are currently available
// Input: Current working directory, Output: The save files (.txt).
void check_files(const string& directory) {
    vector<string> save_record; // Vector to hold found save file names

    DIR* dir = opendir(directory.c_str());
    if (dir == nullptr) {
        cerr << "Could not open directory: " << directory << endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        string filename = entry->d_name;
        if (filename.size() > 4 && filename.substr(filename.size() - 4) == ".txt") {
            // Append the filename (without the extension) to the vector
            save_record.push_back(filename.substr(0, filename.size() - 4));
        }
    }

    closedir(dir);

    // If there are no saved games, inform the user
    if (save_record.empty()) {
        cout << "*******************************" << endl;
        cout << "*            Saves            *" << endl;
        cout << "*-----------------------------*" << endl;
        cout << "You have no saved games!" << endl;
        cout << "*******************************" << endl;
    } else {
        // Otherwise, list out all the saved games
        cout << "*******************************" << endl;
        cout << "*            Saves            *" << endl;
        cout << "*-----------------------------*" << endl;
        for (size_t i = 0; i < save_record.size(); i++) {
            cout << (i + 1) << ". " << save_record[i] << endl;
        }
        cout << "*******************************" << endl;
    }
}

// Function to write a save file
// Input: The current game data. Output: A .txt saved at the current working directory containing the current game data.
void save_files(const Gamedata& current_game) {
    string filename;
    
    cout << "Enter a unique name for your save file: ";
    cin >> filename;

    ofstream fout(filename + ".txt");  // Include directory in the path
    if (fout.fail()) {
        cout << "Error in file opening!" << endl;
        exit(1);
    } else {
        // Write player data
        fout << current_game.progression_level << " "
             << current_game.player.playerName << " "
             << current_game.player.playerHealth << " "
             << current_game.player.playerPower << " "
             << current_game.player.playerMaxHealth << " "
             << current_game.player.playerExp << " "
             << current_game.player.playerMaxExp << " "
             << current_game.player.playerLevel << endl;

        // Write inventory items (one item per line)
        for (const auto& item : current_game.player.inventory.items) {
            fout << item.first << " " << item.second << endl;  // Each item on a new line
        }

        // Indicate the start of skills
        fout << "SKILLS" << endl;  // Optional header to indicate the skills section

        // Write player skills
        for (const auto& skill : current_game.player.playerSkills) {
            fout << skill << " ";  // Skills space-separated
        }
        fout << endl;  // New line after skills

        fout.close();
    }
}

// Function to load save files
// Input: the current address of the game data struct, the current directory. Output: game data read from a save file.
void load_files(Gamedata& gameData, const string& directory) {
    vector<string> save_record;  // Vector to hold save file names

    // Load save files from the directory
    DIR* dir = opendir(directory.c_str());
    if (dir == nullptr) {
        cerr << "Could not open directory: " << directory << endl;
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        string filename = entry->d_name;
        if (filename.size() > 4 && filename.substr(filename.size() - 4) == ".txt") {
            save_record.push_back(filename.substr(0, filename.size() - 4));  // Store names without extension
        }
    }
    closedir(dir);

    // If no save files found, inform the user
    if (save_record.empty()) {
        cout << "No save files found in the directory." << endl;
        return;
    }

    // Display available save files
    cout << "Available save files:" << endl;
    for (size_t i = 0; i < save_record.size(); i++) {
        cout << (i + 1) << ". " << save_record[i] << endl;
    }

    // Get user input for the save file number
    int num;
    cout << "Enter the save file number: ";
    cin >> num;

    if (num <= 0 || num > static_cast<int>(save_record.size())) {
        cerr << "Invalid save file number!" << endl;
        return;
    }

    // Construct filename from user input
    string save_name = directory + "/" + save_record[num - 1] + ".txt";
    ifstream fin(save_name);
    if (!fin.is_open()) {
        cerr << "Error opening file: " << save_name << endl;
        exit(1);
    }

    string line;

    // Read player data
    if (getline(fin, line)) {
        istringstream iss(line);
	        string progression_level_str, playerName, playerHealth_str, playerPower_str, 
               playerMaxHealth_str, playerExp_str, playerMaxExp_str, playerLevel_str;

        iss >> progression_level_str >> playerName >> playerHealth_str >> playerPower_str 
            >> playerMaxHealth_str >> playerExp_str >> playerMaxExp_str >> playerLevel_str;

        // Convert string values to integers
        try {
            gameData.progression_level = std::stoi(progression_level_str);
            gameData.player.playerName = playerName; // Name remains a string
            gameData.player.playerHealth = std::stoi(playerHealth_str);
            gameData.player.playerPower = std::stoi(playerPower_str);
            gameData.player.playerMaxHealth = std::stoi(playerMaxHealth_str);
            gameData.player.playerExp = std::stoi(playerExp_str);
            gameData.player.playerMaxExp = std::stoi(playerMaxExp_str);
            gameData.player.playerLevel = std::stoi(playerLevel_str);
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid number format in save file: " << e.what() << endl;
            exit(1);
        } catch (const std::out_of_range& e) {
            cerr << "Number out of range in save file: " << e.what() << endl;
            exit(1);
        }
    }

    // Clear previous inventory and skills
    gameData.player.inventory.items.clear();
    gameData.player.playerSkills.clear();

    // Read inventory items
    while (getline(fin, line) && line != "SKILLS") {  // Stop reading when "SKILLS" is encountered
        istringstream iss(line);
        string itemName;
        int itemValue;

        // Read the item name (which may contain spaces)
        size_t lastSpace = line.find_last_of(' ');
        if (lastSpace != std::string::npos) {
            itemName = line.substr(0, lastSpace);  // Everything before the last space
            itemValue = std::stoi(line.substr(lastSpace + 1));  // Value after the last space
            gameData.player.inventory.items[itemName] = itemValue;  // Store in map
        }
    }

    // Read player skills (after the "SKILLS" line)
    if (getline(fin, line) && !line.empty()) {
        istringstream iss(line);
        string skill;
        while (iss >> skill) {
            gameData.player.playerSkills.push_back(skill);  // Read skills as strings
        }
    }

    fin.close();
}

// Function to delete a save file (Not implemented)

void delete_files(vector<string> &save_record) {
    check_files(directory);
    int input;
    cin >> input;
    // Remove the specified file from the record
    save_record.erase(save_record.begin() + (input-1));
		cout << "The savefile " << input << " has been removed!" << endl;
		return;
}
