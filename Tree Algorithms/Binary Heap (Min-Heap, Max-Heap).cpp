#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
public:
    vector<int> heap; // Vector to store heap elements

    // Function to insert an element into the heap
    void insert(int val) {
        heap.push_back(val); // Add the new element at the end
        int index = heap.size() - 1; // Get the index of the new element

        // Move the new element to its correct position in the heap
        while (index != 0) {
            int parentIndex = (index - 1) / 2; // Get the parent index
            if (heap[index] >= heap[parentIndex]) break; // If the heap property is satisfied

            swap(heap[index], heap[parentIndex]); // Swap with parent
            index = parentIndex; // Move up to the parent index
        }
    }

    // Function to get the minimum element (the root of the min-heap)
    int getMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty!"); // Throw an error if the heap is empty
        }
        return heap[0]; // Return the root element
    }

    // Function to remove the minimum element (the root of the min-heap)
    void removeMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty!"); // Throw an error if the heap is empty
        }

        heap[0] = heap.back(); // Replace root with the last element
        heap.pop_back(); // Remove the last element

        // Heapify down from the root
        int index = 0;
        int size = heap.size();

        while (true) {
            int leftChild = 2 * index + 1; // Left child index
            int rightChild = 2 * index + 2; // Right child index
            int smallest = index; // Assume the current index is the smallest

            // Check if the left child exists and is smaller than the current smallest
            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild; // Update smallest index
            }

            // Check if the right child exists and is smaller than the current smallest
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild; // Update smallest index
            }

            // If the smallest is still the current index, break the loop
            if (smallest == index) break;

            swap(heap[index], heap[smallest]); // Swap with the smallest child
            index = smallest; // Move down to the smallest child index
        }
    }
};

class MaxHeap {
public:
    vector<int> heap; // Vector to store heap elements

    // Function to insert an element into the heap
    void insert(int val) {
        heap.push_back(val); // Add the new element at the end
        int index = heap.size() - 1; // Get the index of the new element

        // Move the new element to its correct position in the heap
        while (index != 0) {
            int parentIndex = (index - 1) / 2; // Get the parent index
            if (heap[index] <= heap[parentIndex]) break; // If the heap property is satisfied

            swap(heap[index], heap[parentIndex]); // Swap with parent
            index = parentIndex; // Move up to the parent index
        }
    }

    // Function to get the maximum element (the root of the max-heap)
    int getMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty!"); // Throw an error if the heap is empty
        }
        return heap[0]; // Return the root element
    }

    // Function to remove the maximum element (the root of the max-heap)
    void removeMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty!"); // Throw an error if the heap is empty
        }

        heap[0] = heap.back(); // Replace root with the last element
        heap.pop_back(); // Remove the last element

        // Heapify down from the root
        int index = 0;
        int size = heap.size();

        while (true) {
            int leftChild = 2 * index + 1; // Left child index
            int rightChild = 2 * index + 2; // Right child index
            int largest = index; // Assume the current index is the largest

            // Check if the left child exists and is larger than the current largest
            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild; // Update largest index
            }

            // Check if the right child exists and is larger than the current largest
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild; // Update largest index
            }

            // If the largest is still the current index, break the loop
            if (largest == index) break;

            swap(heap[index], heap[largest]); // Swap with the largest child
            index = largest; // Move down to the largest child index
        }
    }
};

// Main function to demonstrate Min-Heap and Max-Heap
int main() {
    MinHeap minHeap; // Create a MinHeap object
    MaxHeap maxHeap; // Create a MaxHeap object

    // Inserting elements into MinHeap
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(4);
    minHeap.insert(45);

    cout << "Min Heap minimum: " << minHeap.getMin() << endl; // Output the minimum element
    minHeap.removeMin(); // Remove the minimum element
    cout << "Min Heap minimum after removal: " << minHeap.getMin() << endl; // Output the new minimum

    // Inserting elements into MaxHeap
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(1);
    maxHeap.insert(15);
    maxHeap.insert(5);
    maxHeap.insert(4);
    maxHeap.insert(45);

    cout << "Max Heap maximum: " << maxHeap.getMax() << endl; // Output the maximum element
    maxHeap.removeMax(); // Remove the maximum element
    cout << "Max Heap maximum after removal: " << maxHeap.getMax() << endl; // Output the new maximum

    return 0; // Indicate that the program ended successfully
}

