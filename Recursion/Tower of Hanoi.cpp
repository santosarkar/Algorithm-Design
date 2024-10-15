
#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If there's only one disk, move it from source to destination
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int num;
    cout << "Enter the number of disks: ";
    cin >> num; // Take input from the user

    cout << "The sequence of moves involved in the Tower of Hanoi are:\n";
    towerOfHanoi(num, 'A', 'C', 'B'); // A is source, C is destination, B is auxiliary

    return 0; // Indicate that the program ended successfully
}
