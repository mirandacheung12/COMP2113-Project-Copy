#include "inventory.h"
#include "player.h"
#include <iostream>
using namespace std;

// Add item to inventory
void Inventory::addItem(const string &itemName) {
    items[itemName]++;
    cout << itemName << " added to inventory." << endl;
}

// Display inventory items
void Inventory::displayItems() const {
    cout << "Inventory:" << endl;
    for (const auto &item : items) {
        cout << item.first << ": " << item.second << endl;
    }
}

// Delete inventory item
void Inventory::deleteItem(const string &itemName) {
    if (items[itemName] > 0) {
        items[itemName]--;
        cout << itemName << " removed from inventory." << endl;
    } else {
        cout << "No " << itemName << " to remove!" << endl;
    }
}

//Use inventory item
void Inventory::useItem(const string &itemName, Player &player) {
    //verify if inputted item exists in inventory
    if (items.find(itemName) == items.end()) {
    	cout << itemName << " not in inventory!" << endl;
	    return; //exit inventory if inputted item does not exist
    }
    
    if (items[itemName] > 0) {
        cout << "Using " << itemName << "!" << endl;
        // Implement item effects on player
        if (itemName == "Health Potion") {
             player.playerHealth += 50;
            if (player.playerHealth > player.playerMaxHealth) {
                player.playerHealth = player.playerMaxHealth;
            }
            cout << "Health increased by 50." << endl;
        } else if (itemName == "Power Boost") {
            player.playerPower += 100;
            cout << "Power increased by 100." << endl;
        }
        items[itemName]--;
    } else {
        cout << "No " << itemName << " left!" << endl;
    }
}
