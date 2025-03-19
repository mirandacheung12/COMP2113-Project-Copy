#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "player.h"
#include "battle.h"
#include "inventory.h"
#include "minigame.h"
#include "GAME_SAVE.h"
using namespace std;

int progress;

map <int, string> stagesname={{1,"Subway"},{2,"Pyramid"},{3,"Abandoned Manor"},{4,"Hell"},{5,"Final Boss"}};

int main()
{
    int input;
    Player player;
		Gamedata gamedata;
		gamedata.player = player;
		gamedata.progression_level = progress;
		directory = get_current_directory();
    cout<<"--------------------"<<endl;
    cout<<"1.New Game"<<endl;
    cout<<"2.Load Game"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Please enter the corresponding number for next action:"<<endl;
    while (true)
    {
        cin>>input;
        if (input==2)
        {
						load_files(gamedata,directory);
		progress = gamedata.progression_level;
		player = gamedata.player;
		
						break;
					
				}
        else if (input==1)
        {
            cout<<"Welcome, adventurer! In this game, you are going to explore 4 different dungeons, each filled with random enemies."<<endl;
            cout<<endl;
            cout<<"During the adventure, you will collect items, experience points and skills to strengthen yourself, so that you can face the final boss and defeat it!"<<endl;
            cout<<endl;
            cout<<"Please enter your name:"<<endl;
            string Name;
            cin>>Name;
            progress=1;
            player = {Name,100, 25, 100, 0, 100, 1};
            cout<<player.playerName<<", please enjoy your game!"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid input. Try again!!!"<<endl;
        }
    }
    while(true)
    {
        if (progress==6)
        {
            char user_input;
	    cout << "Would you like to restart your progress from level 1 with your current status? (y/n): " << endl;
	    cin >> user_input;
	    if (user_input == 'y') {
    		  progress = 1;
	    }
        }
        cout<<"--------------------"<<endl;
        cout<<"1. Battle"<<endl;
        cout<<"2. Status"<<endl;
        cout<<"3. Inventory"<<endl;
        cout<<"4. Mini-Game"<<endl; 
        cout<<"5. Help"<<endl;
        cout<<"6. Exit"<<endl;
				cout<<"7. Save Game"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Please enter the corresponding number for next action:"<<endl;
        cin>>input;
        if (input==1)
        {
            if (progress != 6) {
    		Battle(player, progress);
	    } else {
    		cout << "You have already completed our game, restart your progress if you would like to play." << endl;
	    }
        }
        else if (input==2)
        {
            cout<<"--------------------"<<endl;
            cout<<"Player Name: "<<player.playerName<<endl;
            cout<<"Health Points: "<<player.playerHealth<<"/"<<player.playerMaxHealth<<endl;
            cout<<"Power: "<<player.playerPower<<endl;
            cout<<"Level: "<<player.playerLevel<<endl;
            cout<<"Experience Point: "<<player.playerExp<<"/"<<player.playerMaxExp<<endl;
	    cout<<"Progression: "<<progress<<"-"<<stagesname[progress]<<" ("<<progress<<"/5)"<<endl;
            cout<<"Skills acquired:"<<endl;
	    if (player.playerSkills.empty()){
	    	cout << "None" << endl;
	    } else {
                for (int skill_index=0; skill_index < player.playerSkills.size(); skill_index++)
                {
                	if (skill_index == player.playerSkills.size() - 1){
				cout << player.playerSkills[skill_index] << endl;
			} else {
				cout << player.playerSkills[skill_index] << " , ";
			}
			
                }
	    }
            cout<<"--------------------"<<endl;
            cout<<"Enter 1 to continue"<<endl;
            cin>>input;
            while(input!=1)
            {
                cin>>input;
            }
        }
        else if (input==3)
        {
            player.inventory.displayItems();
        }
        else if (input ==4)
        {    
            ChooseMiniGame(player);
        }
        else if (input==5)
        {
            cout<<"--------------------"<<endl;
            cout<<"Battle: Enter the next battle."<<endl;
            cout<<"Status: Check the current status of character."<<endl;
            cout<<"Inventory: Check or interact with inventory."<<endl;
            cout<<"Minigame: Play minigames for extra rewards."<<endl;
            cout<<"Exit: Exit game."<<endl;
						cout<<"Save Game: Save game."<<endl;
            cout<<"--------------------"<<endl;
            cout<<"Enter 1 to continue"<<endl;
            cin>>input;
            while(input!=1)
            {
                cin>>input;
            }
        }
        else if (input==6)
        {
            cout<<"GoodBye!!!"<<endl;
            break;
        }
				else if (input == 7)
				{
						gamedata.progression_level = progress;
					gamedata.player = player;
						save_files(gamedata);
						
				}
        else
        {
            cout<<"Invalid input. Try again!!!"<<endl;
        }
    }
    return 0;
}
