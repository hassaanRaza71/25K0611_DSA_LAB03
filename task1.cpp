#include <iostream>
using namespace std;

void adjacentSwapper(int arr[], int size) {
    int totalSwaps = 0;
    int totalComparisons = 0;
    int passesExecuted = 0;
    int worstCasePasses = size - 1;

    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        passesExecuted++;

        for (int j = 0; j < size - 1 - i; j++) {
            totalComparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                totalSwaps++;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    int passesSaved = worstCasePasses - passesExecuted;
    int theoreticalWorstCaseComparisons = size * (size - 1) / 2;

    cout << "Total number of swaps made: " << totalSwaps << endl;
    cout << "Total comparisons made: " << totalComparisons << endl;
    cout << "Passes saved compared to worst case: " << passesSaved << endl;
    cout << "Theoretical worst-case comparisons N(N-1)/2: " << theoreticalWorstCaseComparisons << endl;
}

int main() {
    int arr[] = {1, 5, 2, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    adjacentSwapper(arr, size);

    return 0;
}
