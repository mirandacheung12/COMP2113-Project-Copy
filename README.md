# COMP2113-Project-Copy
# Group20 Project: Monster Hunter
## Group members: 
- Member 1: Cheung Miranda Ching Yuet
- Member 2: -
- Member 3: -
- Member 4: -
- Member 5: -
## Project Description
This is a text-based action/adventure game where players go through dungeons to defeat enemies, collect rewards and level up. Enemy encounters are randomized so each playthrough is unique, offering a fresh experience every time. Optional mini-games, namely "Number Guess", "Math Question", "Rock, Paper, Scissors" and "Word Scramble" are included for players to earn extra reward items or boost stats like health, power and experience points. 
## List of implemented features and the corresponding coding requirements
- **Inventory System**: Players can collect and use items to aid in their journey.
- **Skill Acquisition**: Players can acquire and use various skills to defeat  enemies.
- **Leveling System**: Players gain points from defeating enemies, which increases their power and health.
- **Mini-Games**: Players can play mini-games to earn rewards that help them progress through the main game.
- **Battle System**: Players encounter randomized enemies in each stage. Enemies randomly attack or use skill.
- **Save&Load System**: Players can save their game after each stage, exit the game, and load their progress again.

1. **Generation of Random Events:**
   - Implemented through randomized enemy encounters in each dungeon.
   - Types of rewards are also randomized and can include reward items like "Health Potions" and "Power Boosts," or enhancements to stats such as health, power, and experience points.
   - Enemies can also randomly choose skills to use in battle with the player.
2. **Data Structures for Storing Data:**
   - Examples include: managing player stats (struct), inventory (vector), skills (map) and game state.
3.  **Dynamic Memory Management:**
   - Inventory updates and skill acquisitions are handled dynamically in maps and vectors. 
4. **File Input/Output:**
   - Saves and loads game progress from .txt files.
5. **Program Codes in Multiple Files:**
   - Codes for major parts of the game (i.e. main menu, battle, save menu, etc) are in separate files for readability and easier maintenance/updates.

## List of non-standard C/C++ libraries
No non-standard C/C++ libraries are used in the project.

## Compilation and execution instructions
```bash
git clone https://github.com/mirandacheung12/COMP2113-Project-Copy.git
Enter the following commands after downloading:
make main
To play: 
./main
Follow the instructions on the screen to navigate through the game.
Use the menu to access the map, inventory and other commands.
Defeat enemies, collect rewards, and level up to progress through the dungeons.
