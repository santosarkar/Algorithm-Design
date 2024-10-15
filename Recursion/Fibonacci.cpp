
#include <iostream>
using namespace std;

// Function to calculate Fibonacci using recursion
int fibonacci(int n) {
    // Base cases: Fibonacci(0) = 0, Fibonacci(1) = 1
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Recursive case: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num; // Take input from the user

    if (num < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    } else {
        cout << "Fibonacci of " << num << " is " << fibonacci(num) << endl; // Print the Fibonacci number
    }

    return 0; // Indicate that the program ended successfully
}
