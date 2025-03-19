// libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cctype>
#include <algorithm>


// code files
#include "battle.h"
#include "player.h"
#include "pointCol.h"
#include "skillUnlock.h"
#include "GAME_SAVE.h"
#include "minigame.h"
#include "drawEnemy.h"

using namespace std;
// function to perform attack, input: player attributes, enemy attributes, useSkill 
string performAttack(Player &player, Enemy &enemy, bool useSkill) {
    int skill_choice; // variable for player skill choice
    bool skill_used = false; // Track if a player was used
    string Selected_Skill_Name; // variable for player skill choice name
    bool dodge = false; // intial dodge for player skill 'Teleportation'
    
    if (useSkill) { // if user uses skill
        cout << "Your skillsets" << endl; 

        // displays the skillsets of the player
        for (int player_skill_index = 0; player_skill_index < player.playerSkills.size(); player_skill_index++) {
            string skill_name = player.playerSkills[player_skill_index];
            // Iterate through the skills to find details about the player's skill		
            for (const auto& skill_data : skills) {
                if (skill_data.SkillName == skill_name) {
                    // Show skill name and remaining cooldown
                    cout << player_skill_index + 1 << ". " << skill_data.SkillName;
                    cout << " (Remaining Cooldown: " << skill_data.SkillRemainingCooldown 
                         << " / " << skill_data.SkillCooldown << ")" << endl;
                }
            }
        }

        cin.ignore(); // Clear the input buffer before reading the skill choice
        cout << "Select the skill number you would like to use: "; // prompt player skill choice 
        cin >> skill_choice;
	cout << endl;
        Selected_Skill_Name = player.playerSkills[skill_choice - 1]; // Get the selected skill name 

        // Iterate through the skills to find the selected skill's details
        for (int use_skill_index = 0; use_skill_index < skills.size(); use_skill_index++) {
            if (skills[use_skill_index].SkillName == Selected_Skill_Name) {
                Skill &Selected_Skill = skills[use_skill_index]; // Reference to the selected skill

                // Check if the skill is on cooldown
                if (Selected_Skill.SkillRemainingCooldown > 0) {
                    cout << "Skill is on cooldown! Remaining cooldown: " << Selected_Skill.SkillRemainingCooldown << endl;
                    cout << endl;
		    return "Continue"; // Exit without decrementing cooldown
                }

                // Skill can be used
                if (Selected_Skill.SkillName == "InstantKill") {		                    
		    // Check if enemy health is low enough for Instant Kill
                    if (enemy.enemyHealth <= 50) {
			cout << "Your move: You used " << Selected_Skill.SkillName << " and instantly killed the enemy!" << endl; // skill sucessfully used
			cout << "You have defeated " << enemy.enemyName << "!" << endl; 
                        return "Win"; // Player wins the game
                    } else {
                        cout << "Enemy health is too high for InstantKill! It must be 50 or below." << endl; // prompt the message saying skill is not succesfully used
			cout << endl;
			return "Continue"; // Exit without using the skill
                    }
                } else if (Selected_Skill.SkillName == "Teleportation") { // teleportation skill
                    enemy.enemyHealth -= player.playerPower; // Use player power for attack
		    cout << "Your move: You attack the enemy! You dealt " << player.playerPower << " damage." << endl;
	            // Check if the enemy is defeated
                    if (enemy.enemyHealth <= 0) {
                        cout << "You have defeated " << enemy.enemyName << "!" << endl;
                        return "Win"; // Player wins the game
                    } else {
                        cout << "Your move: You dodged the enemy's attack!" << endl; // Notify the player about dodging
		    	cout << endl;
			dodge = true; // set dodge to true when player uses teleportation to dodge the enemy attack
		    }
                } else {
                    enemy.enemyHealth -= Selected_Skill.SkillDamage; // Use the skill's damage to attack enemy

                    // Ensure enemy health does not go negative
                    if (enemy.enemyHealth < 0) {
                        enemy.enemyHealth = 0; // Set to zero if it goes negative
                    }

		    // display the player skill used on the enemy 
		    cout << "Your move: You used " << Selected_Skill.SkillName << " and dealt " << Selected_Skill.SkillDamage << " damage!" << endl;
                    
		}

                // Mark that a skill was used
                skill_used = true;

                // Step 3: Check for win condition after the attack
                if (enemy.enemyHealth <= 0) {
                    cout << "You have defeated " << enemy.enemyName << "!" << endl;
                    return "Win";
                }
		
		
                // Exit the loop after processing the skill
                break;
            }
        }
    } else {
        // Use regular attack if not using a skill
        enemy.enemyHealth -= player.playerPower;

        // Ensure enemy health does not go negative
	cout << "Your move: You attack the enemy! You dealt " << player.playerPower << " damage." << endl;
    	if ( enemy.enemyHealth <= 0) {
		
		cout << "You have defeated " << enemy.enemyName << "!" << endl;
		return "Win";
	}
    }
    if (dodge == false){ // if user used teleportation, enemy move will be skipped
        // Enemy move
    	srand(time(0));
    	if (!enemy.skills.empty()) {
        	int enemy_action = rand() % 2; // Randomly choose attack or skill
        	if (enemy_action == 0) {
	    		// Enemy performs a regular attack
            		player.playerHealth -= enemy.enemyPower; // Decrease player's health by enemy's attack power
	 	        cout << "Enemy move: You have been attacked! " << enemy.enemyName << " dealt " << enemy.enemyPower << " damage to you." << endl;
            		cout << endl;
	    
		} else {
	    		// Enemy uses a random skill
            		int enemy_skill_index = rand() % enemy.skills.size();  // Select a random skill index
            		player.playerHealth -= enemy.skills[enemy_skill_index].enemySkillDamage; // Decrease player's health by the skill's damage
	    		// display the enemy skill attack on the player
            		cout << "Enemy move: " << enemy.enemyName << " used " << enemy.skills[enemy_skill_index].enemySkillName << " and dealt " << enemy.skills[enemy_skill_index].enemySkillDamage << " damage!" << endl;
            		cout << endl;
		}
    	} else {
		// If the enemy has no skills, perform a regular attack
        	player.playerHealth -= enemy.enemyPower; // Decrease player's health by enemy's attack power      
		cout << "Enemy move: You have been attacked! " << enemy.enemyName << " dealt " << enemy.enemyPower << " damage to you." << endl;
 		cout << endl;
	}
    }

    // Check if player is defeated
    if (player.playerHealth <= 0) {
    	
        cout << "You have been defeated... Exiting the dungeon." << endl;
        return "Lost"; // Exit the function when lost, battle is over
    }

    // Step 4: Update cooldowns for all skills at the end of the function
    for (auto& skill : skills) {
        if (skill.SkillRemainingCooldown > 0) {
            skill.SkillRemainingCooldown--; // Decrease remaining cooldown
        }
    }

    // If a skill was used, reset its cooldown
    if (skill_used) {
        for (auto& skill : skills) {
            if (skill.SkillName == Selected_Skill_Name) {
                skill.SkillRemainingCooldown = skill.SkillCooldown; // Reset cooldown here
                break;
            }
        }
    }

    return "Continue"; // Indicate that the battle is ongoing
}

// function to start battle, input: player attributes, enemy attributes, stage, stage-level
string battle_start(Player &player, Enemy &enemy, int stage, int level) {
    int action; // Variable to store the player's chosen action
    int maxEnemyHealth = enemy.enemyHealth; // Store the enemy's maximum health for status display

    
    cout << "Enemy: " << enemy.enemyName << endl; // Display the enemy's name
  
    while (true) { // Loop until a valid action is performed or the player runs away
    	cout << "********************************" << endl; 
	drawEnemy(enemy.enemyName); // draw the enemy by inputting the name which retrieves a ascii character
	cout << "Stage - level: " << stage << " - " << level << endl;
        cout << "Enemy Status" << endl;
	cout << "Enemy Name: " << enemy.enemyName << endl; // Show the enemy's name
        cout << "Health: " << enemy.enemyHealth << "/" << maxEnemyHealth << endl;  // Display enemy health
        cout << "Power: " << enemy.enemyPower << endl; // Display enemy power
        cout << "********************************" << endl;
  
        cout << endl;
        cout << "********************************" << endl;
        cout << "Player Status" << endl;
	cout << "Player Name: " << player.playerName << endl; // Show the player's name
	cout << "Level: " << player.playerLevel << endl; // Display player's level
        cout << "Health: " << player.playerHealth << "/" << player.playerMaxHealth << endl; // Display player's health
        cout << "Power: " << player.playerPower << endl; // Display player's attack power
	cout << "Skills: ";
	
	// Check if the player has skills to display
	if (player.playerSkills.empty()){
		cout << "None" << endl; // No skills available
	} else {
		// Display the player's skills
		for (int skill_index = 0; skill_index < player.playerSkills.size(); skill_index++){
			if (skill_index ==  player.playerSkills.size() - 1){
				cout << player.playerSkills[skill_index] << endl; // Last skill without a comma
			} else {
				cout << player.playerSkills[skill_index] << " , "; // Skills separated by commas
			}
		}
	}



	cout << "Experience points: " << player.playerExp << " / " << player.playerMaxExp << endl;  // Show experience points
        cout << "*********************************" << endl;    
	cout << endl;
	    
        // Prompt the player to select an action
	cout << "Select your action: " << endl;
        cout << "1. Attack" << endl;
        cout << "2. Items" << endl;
        cout << "3. Skills" << endl;
        cout << "4. Run away" << endl;
        cout << "Your action: ";
	cin >> action;

	// player chooses attack
        if (action == 1) {
            
	    cout << endl; 
            
	    // Call performAttack with false to use regular power
            string result = performAttack(player, enemy, false);
            if (result == "Win" || result == "Lost") {
                return result; // Exit the battle if win or lost
            }

	    cout << endl;
	
	// player chooses inventory
        } else if (action == 2) {
            cout << "Opening items..." << endl; // Notify the player that items are being accessed
            // Call inventory function to display items
	    player.inventory.displayItems(); // Prompt for item choice
	    cout << "Enter the name of the item you wish to use: ";
	    string itemName;
	    cin.ignore(); // Clear the input buffer
	    getline(cin,itemName); // Read the item name from input
	    player.inventory.useItem(itemName, player); // Use the selected item
	    cout << endl;

	// player chooses skill
	} else if (action == 3) {
            // Check if the player has skills to use
            if (!player.playerSkills.empty()){
	    	 string result = performAttack(player, enemy, true); // Call performAttack to use a skill
		 if (result == "Win" || result == "Lost") {
                     return result; // Exit the battle if win or lost
                 }
	    } else {
	    	  cout << "You have no skills at the moment..." << endl; // Inform the player if no skills are available
		  cout << endl;
            }

	// player chooses to flee the dungeon
        } else if (action == 4) {
            cout << "Leaving the dungeon..." << endl; // Notify the player about fleeing
            return "Exit"; // Exit the function, player has fled

        } else {
            cout << "Invalid action. Please select again." << endl; // Handle invalid input
	    cout << endl;
	}
    }
}
// run stage, input: stage, award Points, award items, low level boss names, middle level boss names, final level boss names, enemy attributes, player attributes
bool run_stage(int stage, int awardPoints, vector<string> award_item_skill, vector<string>& LowLevelBossNames, vector<string>& MiddleLevelBossNames, vector<string>& FinalLevelBossNames, Enemy &enemy, Player &player){
	int level = 1, enemy_Health, enemy_Power, random_index; // Initialize the current level, Variables for enemy stats and random index for boss selection
	string result, enemy_Name, award; // Variables to store the result of the battle, enemy name, and award

	//Base stats for enemy
	enemy_Health = enemy.enemyHealth; // Store initial enemy health
	enemy_Power = enemy.enemyPower; // Store initial enemy power

	// Loop through the levels of the stage
	while (level <= 3) {
		// Level 1: Select a low-level boss
        	if (level == 1) {
            	    random_index = rand() % LowLevelBossNames.size(); // Randomly select a boss name
        	    enemy.enemyHealth = enemy_Health; // Reset enemy health
                    enemy.enemyPower = enemy_Power;  // Reset enemy power
		    enemy.enemyName = FinalLevelBossNames[random_index]; // Set enemy name
		    award = award_item_skill[0]; // Set award for this level
		
		} else if (level == 2) {
		    // Level 2: Select a middle-level boss
            	    random_index = rand() % MiddleLevelBossNames.size(); // Randomly select a boss name
            	    enemy.enemyHealth =  enemy_Health + 25; // Increase enemy health
                    enemy.enemyPower = enemy_Power + 10; // Increase enemy power
                    enemy.enemyName = FinalLevelBossNames[random_index]; // Set enemy name
        	    awardPoints += 25; // Increase award points for defeating this level
		    award = award_item_skill[1]; // Set award for this level

		} else if (level == 3) {
		    // Level 3: Select the final boss
                    random_index = rand() % FinalLevelBossNames.size();  // Randomly select a boss name
                    enemy.enemyHealth = enemy_Health + 25; // Increase enemy health
                    enemy.enemyPower = enemy_Power + 10; // Increase enemy power
                    enemy.enemyName = FinalLevelBossNames[random_index]; // Set enemy name
		    awardPoints += 25; // Increase award points for defeating this level
		    award = award_item_skill[2]; // Set award for this level
        	}
	        // Display stage and level information
		cout << "Stage " << stage << " Level " << level << endl;		
	  	result = battle_start(player, enemy, stage, level); // Start the battle
                // Check the result of the battle	
		if (result == "Exit" || result == "Lost") {
            		return false; // Exit if the player chose to flee or was defeated
        	} else if (result == "Win") {
			
			 // Player won the battle
			player.playerHealth = player.playerMaxHealth; // Restore player's health
			if (award == award_item_skill[1]){
				// If the award is a skill, unlock it for the player
				auto skill_found = find(player.playerSkills.begin(), player.playerSkills.end(), award); // find if the skill exists in player skillset 
				if (skill_found ==  player.playerSkills.end()){ // if not found, add to  skillset
					cout << "You have unlock a new skill: " << award << endl;
					player.playerSkills.push_back(award);
					skillUnlock(award);
					cout << endl;
				} else {
					cout << "Skill award has been awarded but " << award << " is already in your skillset" << endl; // if found, prompt a message saying its already in the skillset
					cout << endl;
				}
			} else {
				// Otherwise, add the item to the player's inventory
				cout << "You have recieved " << award << "!" << endl;
				player.inventory.addItem(award);
				cout << endl;
			}
			
			pointCol(player, awardPoints); // Award points to the player
			// Level up the player if they have enough experience
			while (player.playerExp >= player.playerMaxExp){
				player.playerPower += 15; // Increase player power
								
				player.playerMaxHealth += 50; // Increase maximum health
				player.playerHealth =  player.playerMaxHealth; // Restore health

				player.playerExp = (awardPoints + player.playerExp) - player.playerMaxExp; // Update experience
				player.playerMaxExp += 50; // Increase maximum experience needed for next level

				player.playerLevel += 1; // Level up the player
				// Display level-up information
				cout << endl;
				cout << "----------------------------------------------------------------" << endl;
				cout << "You have leveled up to level " << player.playerLevel << "!" << endl;
				cout << "Your new Max Health has been increased by 50 Health bar!" << endl;
				cout << "Your new Power has been increased by 15 Power!" << endl;
				cout << "----------------------------------------------------------------" << endl;
				cout << endl;

			}

			 // Check if the player is moving to the next level or completing the stage

			if (level == 2) {
				cout << "=======================================" << endl;
				cout << "Moving to Final Boss of stage " << stage << endl;
				cout << "=======================================" << endl;
				cout << endl;
			}else if (level != 3){
				cout << "=======================================" << endl;
                		cout << "Moving to next level" << endl;
				cout << "=======================================" << endl;
            			cout << endl;
			} else if (level == 3){
				// Player has completed the final level of the stage
				cout << "=============================" << endl;
		                cout << "You have completed stage " << stage << " !" << endl;
				cout << "=============================" << endl;
				return true; // indicate completed stage and returns true
			}
        	}

        	level++; // move to next level
        }	

	return false; // Indicate the stage was not completed sucessfully

}

// stage one settings, input: player attributes
bool stage_one(Player &player) {
    // Define low-level bosses for stage one
    vector<string> lowLevelBosses = {
        "Rat King", "Graffiti Goblin", "Hobo Warlord",
        "Metro Mummy", "Subway Shaman", "Pigeon Sorcerer",
        "Scrap Metal Beast", "Tunnel Troll", "Sewer Snake", "Vagrant Vampire"
    };
    // Define middle-level bosses for stage one
    vector<string> middleLevelBosses = {
        "Mutant Alligator", "Subway Stalker", "Demon of the Underground",
        "Phantom Conductor", "Cyborg Enforcer", "Underground Wraith",
        "Banshee of the Tunnels", "Sewer Beastmaster", "Lurker in the Shadows", "Graffiti Golem"
    };
    // Define big-level bosses for stage one
    vector<string> bigBosses = {
        "Cthulhu's Ratspawn", "The Overlord of the Underground",
        "Metro Leviathan", "Dreaded Subway Demon", "King of the Sewers",
        "Apocalypse Subterran", "The Abyssal Conductor",
        "Eldritch Horror of the Tunnels", "The Dark Railmaster", "Nightmare Beneath the Tracks"
    };

    // Initialize the enemy with base health and power    
    Enemy enemy = {80, 15, {}}; // Health: 80, Power: 15, Skills: empty
    int stage = 1; // Set the current stage number
    // Awards for winning each level in the stage
    vector<string> award_item_skill = {"Health Potion", "Lightning", "Power Boost"};	

    // Run the stage and store the result (true for completed, false for not)
    bool stage_result = run_stage(stage, 30, award_item_skill, lowLevelBosses, middleLevelBosses, bigBosses, enemy, player);
    return stage_result; // Return the result of the stage
}

// stage two settings, input: player attributes
bool stage_two(Player &player) {
    // Define low-level bosses for stage one
    vector<string> lowLevelBosses = {
        "Mummy Guardian", "Pyramid Phantom", "Sphinx Specter",
	"Desert Bandit", "Scarab Swarm", "Cursed Pharaoh",
        "Sand Wraith", "Hieroglyphic Horror", "Anubis' Minion", "Tomb Raider"
    };

    // Define middle-level bosses for stage one
    vector<string> middleLevelBosses = {
        "Egyptian Sorcerer", "Cursed Tomb Raider", "Giant Scorpion",
        "Sandstorm Djinn", "Pyramid Sentinel", "Sphinx Guardian",
        "Undead Mummified King", "Desert Djinn", "Pharaoh's Curse", "Treasure Guardian"
    };

    // Define big-level bosses for stage one
    vector<string> bigBosses = {
        "The Great Sphinx", "Pharaoh of the Abyss",
        "Anubis, God of the Dead", "Cursed Mummy King",
        "The Eternal Guardian", "Sand Leviathan",
        "Ruler of the Desert Tombs", "The Serpent of Chaos",
        "The Wrath of Ra", "The Ancient Curse"
    };
    // Initialize the enemy with base health and power    
    Enemy enemy = {150, 45, {}}; // Health: 120, Power: 30, Skills: empty
    int stage = 2;  // Set the current stage number
    // Awards for winning each level in the stage
    vector<string> award_item_skill = {"Health Potion", "Fireball", "Power Boost"};

    // Run the stage and store the result (true for completed, false for not)
    bool stage_result = run_stage(stage, 70, award_item_skill, lowLevelBosses, middleLevelBosses, bigBosses, enemy, player);
    return stage_result; // Return the result of the stage
}
// stage three settings, input: player attributes
bool stage_three(Player &player) {
    // Define low-level bosses for stage one
    vector<string> lowLevelBosses = {
        "Ghostly Butler", "Haunting Portrait", "Cursed Doll",
        "Wandering Spirit", "Mysterious Footsteps", "Phantom Maid",
        "Creepy Shadow", "Echoing Laughter", "Whispering Ghost", "Abandoned Child"
    };
    // Define middle-level bosses for stage one
    vector<string> middleLevelBosses = {
        "Spectral Hound", "Vengeful Spirit", "Ghostly Apparition",
        "Haunted Mirror", "Cursed Mirror", "The Weeping Woman",
        "Restless Soul", "The Shadowed Figure", "Sinister Presence", "The Lurking Horror"
    };
    // Define big-level bosses for stage one
    vector<string> bigBosses = {
        "The Haunted Lord", "The Phantom of the Manor",
        "The Wraith King", "The Lady of the House",
        "The Cursed Revenant", "The Undying Specter",
        "The Original Owner", "The Dark Guardian",
        "The Keeper of Secrets", "The Abomination of the Manor"
    };
    // Initialize the enemy with base health and power    
    Enemy enemy = {200, 75, {}}; // Health: 180, Power: 45, Skills: empty
    int stage = 3; // Set the current stage number

    // Awards for winning each level in the stage 
    vector<string> award_item_skill = {"Health Potion", "Teleportation", "Power Boost"};
    // Run the stage and store the result (true for completed, false for not)    
    bool stage_result = run_stage(stage, 100, award_item_skill, lowLevelBosses, middleLevelBosses, bigBosses, enemy, player);
    return stage_result; // Return the result of the stage
}
// stage four settings, input: player attributes
bool stage_four(Player &player) {
    // Define low-level bosses for stage one
    vector<string> lowLevelBosses = {
        "Demonic Imp", "Cursed Soul", "Hellhound",
        "Infernal Wraith", "Fire Elemental", 
        "Tormented Spirit", "Shadow Demon", "The Bloodletter", "The Whispering Fiend"
    };
    // Define middle-level bosses for stage one
    vector<string> middleLevelBosses = {
        "Demon Knight", "Hellfire Beast", "Screaming Banshee",
        "The Scourge", "The Reaper", "Infernal Executioner",
        "The Voidwalker", "The Tormentor", "The Vile Sorcerer", "The Bloodthirsty Fiend"
    };
    // Define big-level bosses for stage one
    vector<string> bigBosses = {
        "The Dark Lord", "Satan's Chosen",
        "The Devil Incarnate", "The Master of Hell",
        "The Abyssal Overlord", "The Great Deceiver",
        "The Infernal Tyrant", "The Harbinger of Chaos",
        "The Eternal Damnation", "The Ruler of the Underworld"
    };

    // Initialize the enemy with base health and power
    Enemy enemy = {250, 70, {}}; // Health: 250, Power: 70, Skills: empty
    int stage = 4; // Set the current stage number
	
    // Awards for winning each level in the stage
    vector<string> award_item_skill = {"Health Potion", "InstantKill", "Power Boost"};
    // Run the stage and store the result (true for completed, false for not)   
    bool stage_result = run_stage(stage, 150, award_item_skill, lowLevelBosses, middleLevelBosses, bigBosses, enemy, player);
    return stage_result; // Return the result of the stage
}
// final stage settings, input: player attributes
bool final_stage(Player &player){
    // Initialize the final boss with health, power, name, and skills
    Enemy FinalBoss = {400,100,"Fallen Angel", {
        {"Dark Slash", 70},          // Skill: Dark Slash
        {"Hellfire Barrage", 50},   // Skill: Hellfire Barrage
        {"Laser", 50}      // Skill: Final Judgment with a cooldown of 2 turns
    }};
    
    // Loop until the battle is resolved
    while (true){
    	string result = battle_start(player, FinalBoss, 5, 0); // Start the battle with the final boss
	// Check if the player has won the battle
    	if (result == "Win"){
		cout << "You have defeated the final boss, Congratulations!" << endl;
		
		// item rewards for beating the boss
		vector<string> award_item = {"Health Potion", "Power Boost"};
		for ( int award_index; award_index < award_item.size(); award_index++){
			cout << "You have recieved " << award_item[award_index] << "!" << endl;
                	player.inventory.addItem(award_item[award_index]);
               		cout << endl;
		}

		int awardPoints = player.playerMaxExp * 0.8;
		pointCol(player, awardPoints); // Award 80% of the player max experience points to the player since its' the final boss
    		
		// level up player
		while (player.playerExp >= player.playerMaxExp){
                                 player.playerPower += 15; // Increase player power

                                 player.playerMaxHealth += 50; // Increase maximum health
                                 player.playerHealth =  player.playerMaxHealth; // Restore health

                                 player.playerExp = (awardPoints + player.playerExp) - player.playerMaxExp; // Update experience
                                 player.playerMaxExp += 50; // Increase maximum experience needed for next level

				player.playerLevel += 1; // Level up the player
                                 // Display level-up information
                                 cout << endl;
                                 cout << "----------------------------------------------------------------" << endl;
                                 cout << "You have leveled up to level " << player.playerLevel << "!" << endl;
                                 cout << "Your new Max Health has been increased by 50 Health bar!" << endl;
                                 cout << "Your new Power has been increased by 15 Power!" << endl;
                                 cout << "----------------------------------------------------------------" << endl;
                                cout << endl;

                         }
		return true; // Return true to indicate the player won
	} 
        // If the result is not "Continue", the battle ended without a win
	if (result != "Continue"){
		return false; // Return false to indicate the battle did not continue
	}
    }
}  


//battle stage, input: player attributes, progress level
void Battle(Player &player, int &progress_level) {	
    
    char user_input; // Variable to store user input for choices
    bool stage_result; // Variable to store the result of the stage
     
    Gamedata current_game; // intialize game saving
    while (progress_level <= 5) { // Loop through stages until stage 5
	if (progress_level == 1) {
	    cout << endl;
            cout << "You are in Stage 1!" << endl; // Notify player of the current stage
            stage_result = stage_one(player);  // Call the function for stage one
	    player.playerHealth = player.playerMaxHealth; // Restore player's health after the stage

	} else if (progress_level == 2) {
	    cout << endl;
            cout << "You are in Stage 2!" << endl; // Notify player of the current stage
            stage_result = stage_two(player);  // Call the function for stage two
	    player.playerHealth = player.playerMaxHealth; // Restore player's health after the stage
	    
	} else if (progress_level == 3) {
            cout << endl;
	    cout << "You are in Stage 3!" << endl; // Notify player of the current stage
            stage_result = stage_three(player);  // Call the function for stage three
	    player.playerHealth = player.playerMaxHealth; // Restore player's health after the stage
            
	} else if (progress_level == 4) {
            cout << endl;
	    cout << "You are in Stage 4!" << endl; // Notify player of the current stage
            stage_result = stage_four(player);  // Call the function for stage four
	    player.playerHealth = player.playerMaxHealth; // Restore player's health after the stage
	    
	} else if (progress_level == 5){
	    cout << endl;
	    cout << "You are in the final stage!" << endl; // Notify player of the current stage
	    stage_result = final_stage(player); // Call the function for stage four
	    player.playerHealth = player.playerMaxHealth; // Restore player's health after the stage

	}
	
   

	if (stage_result == true){ // If the stage was completed successfully
			//  progress to the next level
        		progress_level++;
			cout << "Would you like to complete side quest to earn rewards? (Y/N) "; // prompt user if they would like to complete side quests for rewards
			
			
			while (true){
				cin >> user_input; // get user input
				if (toupper(user_input) == 'Y'){ // change user input to captical letter
					ChooseMiniGame(player); // if user picks yes (Y), Call a function to choose a mini-game
					break;
				} else if (toupper(user_input) == 'N'){ // break the loop if user doesnt want to play game
					break;
				} else {
					cout << "Invalid input, please try again..." << endl; // to check valid input
				}
	                	
			}

			if (progress_level != 5){
				cout << "Would you like to conitnue? (Y/N) "; // prompt user if they would like to continue on with the stage
			        while (true){   
					cin >> user_input;       
					if (toupper(user_input) == 'N'){ // change user input to captical letter
					  	cout << "Going to main menu" << endl; // if user picks no (N), go back to main menu and notify player 
                                          	cout << endl;
                                          	return; // Exit the function to go to the main menu
                                	} else if (toupper(user_input) == 'Y'){ // if user decides to continue game, break loop and go to next stage
                                         	break;
                         	        } else {
                                	        cout << "Invalid input, please try again..." << endl; // to check valid input
                                 	}
                         	} 
			} else {
				// save game when player wins the final battle to keep the player status
				current_game.progression_level = progress_level; // Record the current progression level
			    current_game.player = player; // Record the current player state
        		save_files(current_game); // Save the game data
				cout << "You have defeated our game, you are taken back to main menu" << endl;
				return;
			}
         
	} else {
                         // if stage was not completed successfully, go back to main menu
                         cout << "You are taken back to main menu" << endl;
                         return; // Exit the function to go to the main menu
        }
    }
}
