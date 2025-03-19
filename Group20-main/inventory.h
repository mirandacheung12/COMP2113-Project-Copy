#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Player;

// Class to manage player's inventory
class Inventory {
public:
    void addItem(const string &itemName); // Add item to inventory
    void useItem(const string &itemName, Player &player); //Use item from inventory
    void deleteItem(const string &itemName); //Delete item from inventory
    void displayItems() const; // Display inventory items
    // Map to store items' names and quantities
    // dynamic memory management for inventory items
    map<string, int> items; 
};

#endif // INVENTORY_H
