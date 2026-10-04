#include <iostream>
using namespace std;

void minimalSwapCrane(int arr[], int size) {
    int actualSwaps = 0;
    int skippedSwaps = 0;
    int totalComparisons = size * (size - 1) / 2;

    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            actualSwaps++;
        } else {
            skippedSwaps++;
        }
    }

    double ratio = 0.0;
    if (totalComparisons > 0) {
        ratio = ((double)actualSwaps / totalComparisons) * 100.0;
    }

    cout << "Total actual swaps: " << actualSwaps << endl;
    cout << "Number of skipped swaps: " << skippedSwaps << endl;
    cout << "Swap-to-Comparison Ratio: " << ratio << "%" << endl;
    cout << "Total Comparisons (N(N-1)/2): " << totalComparisons << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    minimalSwapCrane(arr, size);

    return 0;
}
