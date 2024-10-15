
#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Structure to represent a job
struct Job {
    int id; // Job ID
    int deadline; // Job deadline
    int profit; // Profit for the job
};

// Function to compare jobs based on profit
bool jobComparison(Job a, Job b) {
    return a.profit > b.profit; // Sort in descending order of profit
}

// Function to perform job sequencing
void jobSequencing(const vector<Job>& jobs) {
    int n = jobs.size(); // Number of jobs
    vector<bool> slot(n, false); // Track which slots are filled
    vector<int> result(n); // Store the result (job IDs)
    int totalProfit = 0; // Total profit initialized to 0

    // Sort jobs in descending order of profit
    vector<Job> sortedJobs = jobs;
    sort(sortedJobs.begin(), sortedJobs.end(), jobComparison);

    // Iterate through sorted jobs
    for (const Job& job : sortedJobs) {
        // Find a free slot for this job
        for (int j = min(n, job.deadline) - 1; j >= 0; j--) {
            if (!slot[j]) { // If the slot is free
                slot[j] = true; // Mark the slot as filled
                result[j] = job.id; // Store the job ID
                totalProfit += job.profit; // Add profit to total profit
                break; // Exit the loop as the job has been scheduled
            }
        }
    }

    // Output the result
    cout << "Scheduled jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) { // Print only filled slots
            cout << result[i] << " "; // Job IDs in scheduled order
        }
    }
    cout << "\nTotal profit: " << totalProfit << endl; // Print total profit
}

int main() {
    // Example jobs
    vector<Job> jobs = {
        {1, 2, 100}, // Job ID 1, Deadline 2, Profit 100
        {2, 1, 19},  // Job ID 2, Deadline 1, Profit 19
        {3, 2, 27},  // Job ID 3, Deadline 2, Profit 27
        {4, 1, 25},  // Job ID 4, Deadline 1, Profit 25
        {5, 3, 15}   // Job ID 5, Deadline 3, Profit 15
    };

    jobSequencing(jobs); // Call the job sequencing function

    return 0; // Indicate that the program ended successfully
}
