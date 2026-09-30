#include <iostream>
#include <cmath> 
using namespace std;

int midpointSplitSearch(int arr[], int size, int targetID) {
    if (size <= 0) return -1;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "Error: Conveyor is unsorted. Search aborted." << endl;
            return -1;
        }
    }

    int low = 0;
    int high = size - 1;
    int steps = 0;
    int theoreticalMax = floor(log2(size)) + 1;

    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2;
        double remainingSpacePercent = ((double)(high - low + 1) / size) * 100.0;

        cout << "Step " << steps << ":" << endl;
        cout << " -> Indices: [Low: " << low << " | Mid: " << mid << " | High: " << high << "]" << endl;
        cout << " -> Remaining Search Space: " << remainingSpacePercent << "%" << endl;
        cout << " -> Steps taken so far: " << steps << " vs Theoretical Max: " << theoreticalMax << endl;
        cout << "----------------------------------------" << endl;

        if (arr[mid] == targetID) {
            return mid; 
        }
        else if (arr[mid] > targetID) {
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }

    return -1; 
}
