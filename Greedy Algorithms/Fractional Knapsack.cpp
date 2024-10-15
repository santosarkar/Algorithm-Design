#include <iostream>
#include <vector>
#include <algorithm> // Include for sort
using namespace std;

// Structure to represent an item
struct Item {
    int value; // Value of the item
    int weight; // Weight of the item
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Function to compare two items based on their value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Return true if a has a higher ratio than b
}

// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0; // Initialize total value
    for (auto& item : items) {
        if (capacity == 0) break; // If the knapsack is full, break out of the loop
        
        // If the item can be fully accommodated
        if (item.weight <= capacity) {
            totalValue += item.value; // Add its full value
            capacity -= item.weight; // Decrease the capacity
        } else {
            // Add the fractional part of the item
            totalValue += item.value * ((double)capacity / item.weight);
            capacity = 0; // Knapsack is now full
        }
    }
    return totalValue; // Return the total value
}

int main() {
    int capacity = 50; // Capacity of the knapsack
    vector<Item> items = {
        Item(60, 10), // Value 60, weight 10
        Item(100, 20), // Value 100, weight 20
        Item(120, 30)  // Value 120, weight 30
    };

    double maxValue = fractionalKnapsack(capacity, items); // Get max value
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0; // Indicate that the program ended successfully
}

