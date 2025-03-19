// minigame.h
#include "pointCol.h"
#include "inventory.h"
#include "minigame.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <ctime>
#include <cctype>
#include <vector>





using namespace std;

// to display mini game menu
void minigame_menu() {
    cout << "*******************************" << endl;
    cout << "*         MINI GAME           *" << endl;
    cout << "*-----------------------------*" << endl;
    cout << "* 1. Guessing number          *" << endl;
    cout << "* 2. Maths (+, -, *, /)       *" << endl;
    cout << "* 3. Rock, Paper, Scissors    *" << endl;
    cout << "* 4. Word Scramble            *" << endl;
    cout << "*******************************" << endl;
    cout << "Press 'q' for quit" << endl;
}

// first minigame 
bool playNumberGuessGame(){
    srand((time(0))); // Seed the random number generator
    int randomNum, guessedNum, difficulty_choice, chance = 0;
    // loop for choosing difficulty level
    while (true){

    	cout << endl;
       	cout << "Please enter your difficulty: " << endl;
    	cout << "Option 1: Easy level (guess between 0 to 10)" << endl;
    	cout << "Option 2: Medium level (guess between 0 to 30)" << endl;
    	cout << "Option 3: Hard level (guess between 0 to 50)" << endl;
    
    

    // Determine the random number based on the chosen difficulty
       	cout << "Your option: " << endl;
	cin >> difficulty_choice;
    	if (difficulty_choice == 1) {
            randomNum = rand() % 11; // 0 to 10
            cout << "You have 3 chances" << endl;
            break;
        } else if (difficulty_choice == 2) {
            randomNum = rand() % 31; // 0 to 30
            cout << "You have 3 chances" << endl;
            break;
        } else if (difficulty_choice == 3) {
            randomNum = rand() % 51; // 0 to 50
            cout << "You have 3 chances" << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid difficulty level." << endl;
             
        }
    }

    // Game loop for guessing
    while (chance != 3) {
        cout << "Chance " << chance + 1 << ": ";
        cin >> guessedNum;
	//cout << randomNum << endl; // For us to check the correct number when testing
	    
        // if the guessing number is out of range of the chosen difficulty level, it prompts it must be within the range
	if (guessedNum < 0 ||
            (difficulty_choice == 1 && guessedNum > 10) ||
            (difficulty_choice == 2 && guessedNum > 30) ||
            (difficulty_choice == 3 && guessedNum > 50)) {
            cout << "Number has to be within the option " << difficulty_choice << " range." << endl;
            cout << endl;
	
	// if number is guessed number is higher than random number, it prompts its higher than the random number and increments the chance by 1
	} else if (guessedNum > randomNum) {
            cout << "Your number is higher than the random number." << endl;
            cout << endl;
	    chance++;
		
	// if number is guessed number is lower than random number, it prompts its higher than the random number and increments the chance by 1
        } else if (guessedNum < randomNum) {
            cout << "Your number is lower than the random number." << endl;
            cout << endl;
	    chance++;

	// if number is guessed number is random number, it prompts the you guessed it and ends the while loop indicating game won by return true
        } else { 
            cout << "Congratulations! You guessed it!" << endl;
            cout << endl;
	    return true; // won game        
    	}

    
    }
    // if the user guesses three times and still doesn't guess it, it ends the while loop returning false indicating the game is lost
    cout << "The number was "<< randomNum << endl;
    return false; // lost game 

}




// second minigame 
bool playMathGame() {
    int maths_option, check_ans, ans, turns = 0, num1, num2;

    // Prompt user for math operation
    while(true) {	
	cout << endl;
    	cout << "Please choose your maths problem game (must get 5 correct in a row)" << endl;
    	cout << "Option 1: Addition" << endl;
    	cout << "Option 2: Subtraction" << endl;
    	cout << "Option 3: Multiplication" << endl;
    	cout << "Option 4: Division" << endl;
    	cout << "Your Option: ";
    	cin >> maths_option;
    	cout << endl;

    
    
    	// for addition problem
    	if (maths_option == 1) {
        	cout << "Addition: " << endl;
        	for (turns = 0; turns < 5; turns++) {
			// choosing numbers ranging from 1 to 100 for both num1 and num2
            		num1 = rand() % 100 + 1; 
            		num2 = rand() % 100 + 1;

			// the answer
            		check_ans = num1 + num2;
            		//cout << check_ans << endl; // For checking answer

			// display the round and the problem (e.g. Problem 1: What is 1 + 2? and get the user answer )
	    		cout << "Problem " << turns + 1 << ": What is " << num1 << " + " << num2 << "?" << endl;
            		cout << "Answer: ";
            		cin >> ans;

			// if user does not guess it correct, the for loop will end instantly and return false or else the loop 
			// will continue going till user gets it correct 5 times in a row and returns true
            		if (check_ans != ans) {
                		cout << "Game over... You failed to get it 5 times in a row" << endl;
                		return false; // game over
            		} else {
	    			cout << "Correct!" << endl;
	    	
	    		}
	    	cout << endl;
        	}
		// game won
		return true;
		
	// subtraction problem
    	} else if (maths_option == 2) {
        	cout << "Subtraction: " << endl;
        	for (turns = 0; turns < 5; turns++) {
			// choosing numbers ranging from 1 to 100 for both num1 and num2
            		num1 = rand() % 100 + 1;
            		num2 = rand() % 100 + 1;

			// the answer
        		check_ans = num1 - num2;
	    		//cout << check_ans << endl; // For checking answer

			// display the round and the problem (e.g. Problem 1: What is 1 - 2? and get the user answer )
            		cout << "Problem " << turns + 1 << ": What is " << num1 << " - " << num2 << "?" << endl;
            		cout << "Answer: ";
            		cin >> ans;

			// if user does not guess it correct, the for loop will end instantly and return false or else the loop 
			// will continue going till user gets it correct 5 times in a row and returns true			
            		if (check_ans != ans) {
                		cout << "Game over... You failed to get it 5 times in a row" << endl;
                		return false; // game over
            		} else {
	    			cout << "Correct!" << endl;
            		}
	    		cout << endl;
		}
		// game won
		return true;

	// multiplication problem
    	} else if (maths_option == 3) {
        	cout << "Multiplication: " << endl;
        	for (turns = 0; turns < 5; turns++) {
			// choosing numbers ranging from 1 to 100 for both num1 and num2
            		num1 = rand() % 100 + 1;
            		num2 = rand() % 100 + 1;

			// the answer
            		check_ans = num1 * num2;
            		 //cout << check_ans << endl; // For checking answer

			// display the round and the problem (e.g. Problem 1: What is 1 * 2? and get the user answer )
			cout << "Problem " << turns + 1 << ": What is " << num1 << " * " << num2 << "?" << endl;
            		cout << "Answer: ";
            		
			cin >> ans;

			// if user does not guess it correct, the for loop will end instantly and return false or else the loop 
			// will continue going till user gets it correct 5 times in a row and returns true
            		if (check_ans != ans) {
                		cout << "Game over... You failed to get it 5 times in a row" << endl;
                		return false; // game over
            		} else {
	    			cout << "Correct!" << endl;
	    		}
	    		cout << endl;
        	}
		// game won
		return true;

	// division problem
    	} else if (maths_option == 4) {
        	cout << "Division: " << endl;
        	for (turns = 0; turns < 5; turns++) {
			// choosing numbers ranging from 40 to 100 for num1 
			// but number ranging from 1 to 20 for num2
			// this is to prevent division by 0
            		num1 = rand() % 100 + 40; // Ensure num1 is larger
            		num2 = rand() % 20 + 1;    // Avoid division by zero

			// the answer
            		check_ans = num1 / num2;
            		 //cout << check_ans << endl; // For checking answer

			// display the round and the problem (e.g. Problem 1: What is 1 * 2? and get the user answer )
			cout << "Problem " << turns + 1 << ": What is the quotient of " << num1 << " / " << num2 << "?" << endl;
			cout << "Answer: ";
            		cin >> ans;

			// if user does not guess it correct, the for loop will end instantly and return false or else the loop 
			// will continue going till user gets it correct 5 times in a row and returns true
            		if (check_ans != ans) {
                		cout << "Game over... You failed to get it 5 times in a row" << endl;
                		return false; // game over
            		}
	    			cout << endl;
        	}
		// game won
		return true;

    	} else {
		// user will be given a chance to input a choice again if the input option is not valid
        	cout << "Invalid option selected. Please try again." << endl;
    	}
   }
}
	
// third minigame
bool playRPSGame() {
    char user, computer; // variables for user and computer choices
    int round = 0, win_count = 0; // Initialize win_count and round to 0
    
    // Introduction to the game rules
    cout << "Rock (r) | Paper (p) | Scissors (s)" << endl;
    cout << "To win the game, you must at least win 3 rounds out of 5 rounds" << endl;
    cout << endl;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    vector<char> computer_choice = {'r', 'p', 's'}; // possible choices for computer

   // loop to play 5 rounds
    while (round < 5) {
        cout << "Round " << round + 1 << endl; // display current round number
        cout << "Your choice (r, p, s): "; // prompt user for input
        cin >> user;
	
        user = tolower(user); // convert user input to lower
        computer = computer_choice[rand() % computer_choice.size()]; // randomly select computer choice

        cout << "Computer choice: " << computer << endl; // show computer choice

	// Determin the outcome of the round
        if ((computer == 'r' && user == 's') || 
            (computer == 's' && user == 'p') || 
            (computer == 'p' && user == 'r')) {
            cout << "You lost..." << endl; // user lost this round and round are incremented
            cout << endl;
            round++;
        } else if ((computer == 's' && user == 'r') || 
                   (computer == 'p' && user == 's') || 
                   (computer == 'r' && user == 'p')) {
            cout << "You won..." << endl; // uesr won this round and win_count and round are incremented
            win_count++;
            cout << endl;
            round++;
        } else if ((computer == 'r' && user == 'r') || 
                   (computer == 's' && user == 's') || 
                   (computer == 'p' && user == 'p')) {
            cout << "It's a draw..." << endl; // its a draw and the round won't be counted
            cout << endl;
        } else {
            cout << "Please input a correct choice (r, p, s)" << endl; // invalid option 
            cout << endl;
        }
    }

    // display total rounds won by the user
    cout << "You won " << win_count << " out of 5 rounds" << endl;
    if (win_count >= 3) {
        cout << "You won the game" << endl;
        return true; // Return true if the player won the game
    } else {
        cout << "You lose the game" << endl;
        return false; // Return false if the player lost the game
    }
}


// forth minigame
bool playWordScrambleGame() {
    // words in food categories
    vector<string> food = {
        "apple", "banana", "carrot", "pizza", "sushi",
        "bread", "chicken", "rice", "cheese", "pasta",
        "tomato", "salad", "steak", "fish", "yogurt",
        "chocolate", "broccoli", "muffin", "onion"
    };
	
    // words in jobs categories
    vector<string> jobs = {
        "teacher", "engineer", "doctor", "nurse", "chef",
        "artist", "writer", "programmer", "scientist", "accountant",
        "lawyer", "firefighter", "electrician", "plumber", "designer",
        "manager", "technician", "pilot", "researcher", "salesperson"
    };
	
    // words in animals categories
    vector<string> animals = {
        "dog", "cat", "elephant", "tiger", "giraffe",
        "monkey", "rabbit", "dolphin", "horse", "lion",
        "bear", "penguin", "kangaroo", "zebra", "fox",
        "wolf", "owl", "platypus", "tortoise", "parrot"
    };

    string shuffled_word, random_selected_word; // variables for shuffled word and randomly select word
    char hints; // variable for hint
    int category, word_index, hints_count = 0; // variable for category and word index, and intialize hint_count to 0

    srand(time(0)); 
	
   // use while loop to select a category
    while (true) {
	// prompt the user to choose a category for the word scramble game
    	cout << "Choose the category for word scramble game: " << endl;
        cout << "Category 1: Food " << endl;
	cout << "Category 2: Jobs " << endl;
	cout << "Category 3: Animals " << endl;
	cin >> category;
	
        if (category == 1) { // if user picks the first category: food, it will get the random word of that category using the vector<food> size and the random index
            word_index = rand() % food.size();
            random_selected_word = food[word_index];
            break; // break once valid category is selected
        } else if (category == 2) { // if user picks the second category: jobs, it will get the random word of that category using the vector<jobs> size and the random index
            word_index = rand() % jobs.size();
            random_selected_word = jobs[word_index];
            break; // break once valid category is selected
        } else if (category == 3) { // if user picks the first category: animals, it will get the random word of that category using the vector<animals> size and the random index
            word_index = rand() % animals.size();
            random_selected_word = animals[word_index]; 
            break; // break once valid category is selected
        } else {
	    // Handle invalid input
            cout << "Invalid category. Please select valid choice." << endl;
        }
    }

    //cout << random_selected_word << endl; // Display the selected word for debugging (can be removed in final version)
    shuffled_word = random_selected_word; 
    random_shuffle(shuffled_word.begin(), shuffled_word.end()); // shuffle the letters of the word
    cout << "You have 8 chance to guess the word: " << shuffled_word << endl; // Inform the user about the number of chances

    string user_guess; // Variable to store user's guess 
    int chance = 0; // Counter for the number of chances taken

    // Loop until the user has used all their chances
    while (chance != 8) {
        cout << "Chance " << chance + 1 << " Answer: "; // Prompt for user input
        cin >> user_guess;
	    
	// Check if the user's guess is correct
        if (user_guess == random_selected_word) {
            cout << "Congratulations, you won!" << endl;
            return true; // Return true if the game is won
        } else {
            cout << "Wrong answer..." << endl; // Inform the user of their incorrect guess
            cout << endl;

	    // Offer hints after 3 incorrect guesses
            if (chance >= 2 && hints_count != 3) {
                cout << "Do you want hints (Y/N): " << endl; // Ask if the user wants hints
                cin >> hints;
                if (toupper(hints) == 'Y') {  // If the user wants hints
		    // provide first hint
                    if (hints_count == 0) {
                        cout << "First hint: " << endl;
                        if (random_selected_word.size() > 5) {
                            cout << "(First two letters): " << random_selected_word[0] << " , " << random_selected_word[1] << endl;
                        } else {
                            cout << "(First letter): " << random_selected_word[0] << endl;
			    
                        }
                        hints_count++; // Increment hint counter
			    
		    // provide second hint
                    } else if (hints_count == 1) {
                        cout << "Second hint: " << endl;
                        if (random_selected_word.size() > 5) {
                            cout << "(Last two letters): " << random_selected_word[random_selected_word.size() - 2] << " , " << random_selected_word[random_selected_word.size() - 1] << endl;
                        } else {
                            cout << "(Last letter): " << random_selected_word[random_selected_word.size() - 1] << endl;
                        }
                        hints_count++; // Increment hint counter
			    
		    // provide third hint
                    } else if (hints_count == 2) {
                        cout << "Last hint: " << endl;
                        cout << "(Middle letter): " << random_selected_word[(random_selected_word.size() - 1) / 2] << endl;
                        cout << "No more hints..." << endl;
                        cout << endl;
                        hints_count++; // Increment hint counter
                    }
                }
            }
        }
	    
	// Offer an option to quit after 5 incorrect guesses
        if (chance >= 5) {
            cout << "Press 'q' to quit" << endl; // Inform the user how to quit
            cout << endl;
        }
	// Check if the user wants to quit
        if (user_guess == "q") {
            break; // exit the guessing loop
        }

        chance++; // Increment the chance counter
    }

    // Inform the user they lost and reveal the correct word
    cout << "You lost.. The correct word was " << random_selected_word << endl;
    return false; // Return false if the game is not won
}

// choosing minigame, input: player attributes
void ChooseMiniGame(Player &player){
	char game_choice; // variable for game choice
	bool game_result; // variable for game result

	// use while loop to get user choice of the game
	while (true){
		cout << endl;
		// display mini game menu
		minigame_menu();
		cout << "Choose your mini game option: " << endl; // get user input chocie game
		cin >> game_choice;
		if (game_choice == '1'){
			game_result = playNumberGuessGame(); // play random guess game if user picks choice 1
		} else if (game_choice == '2'){
			game_result = playMathGame(); // play math game if user picks choice 2
		} else if (game_choice == '3'){
			game_result = playRPSGame(); // play rock paper siccors game if user picks choice 3
		} else if (game_choice == '4'){
			game_result = playWordScrambleGame(); // play word scramble game if user picks choice 4
		} else if (game_choice == 'q'){
			break; // end this minigame if user decides not to play
		} else {
			cout << "Invalid choice. Please select the mini game" << endl; // if user input invalid choice, it will display the minigame menu and prompt for user input again
			cout << endl;
			minigame_menu();
		}
		if (game_result) { // if game is won
            		
			srand(time(0)); // seed the random number generator
			int choice = rand() % 2; // random number between 0 and 1

			if (choice == 0){ // if the random choice number is 0

				// the list of reward item for user can have
				vector <string> items = {"Health Potion", "Power Boost"};

				// randomizing the items based on the vector<item> size
				int randomized_item_index = rand() % items.size();

				// get the random item
				string randomized_item = items[randomized_item_index];

				// prompt the user has recieved this item and adds to their inventory
                        	cout << "You have recieved " << randomized_item << "!" << endl;
                        	player.inventory.addItem(randomized_item);
                        	cout << endl;
			} else {
                         	// if the random choice number is 1

				// the awardpoints will be from the range of 50 to 300
				int awardPoints = rand()% 301 + 50;

				// prompt the user has won this much points and add onto the point collection
				cout << "You have won " << awardPoints << " points!" << endl;
                         	pointCol(player, awardPoints);
				
				// if the points go beyond the user max experience points, it levels up the user till it is below the max experience points
                         	while (player.playerExp >= player.playerMaxExp){
					// increase user power by 10
                                	player.playerPower += 10;

    					// increase user health by 50
	                                player.playerMaxHealth += 50;

					// intialize user health to max health 
        	                        player.playerHealth =  player.playerMaxHealth;

					// calculate the remaining points based on the given awardpoints, user current experience points and max experience points
                	                player.playerExp = (awardPoints + player.playerExp) - player.playerMaxExp;

					// increase the max experience points by 50 points
        	                        player.playerMaxExp += 50;

					// increase the level
                        	        player.playerLevel += 1;

					// display the leveling up 
					cout << endl;
                                	cout << "----------------------------------------------------------------" << endl;
                                	cout << "You have leveled up to level " << player.playerLevel << "!" << endl;
                                	cout << "Your new Max Health has been increased by 50 Health bar!" << endl;
                                	cout << "Your new Power has been increased by 10 Power!" << endl;
                                	cout << "----------------------------------------------------------------" << endl;
                                	cout << endl;

                         	}
		       }

		} else {
			// display a good luck message if the user loses the games
            		cout << "Better luck next time!" << endl;
        	}
	

	}
}

           
