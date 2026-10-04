#include <iostream>
using namespace std;

void diminishingDistanceScanner(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        double gapPercentage = ((double)gap / size) * 100.0;
        int phaseComparisons = 0;
        int phaseSwaps = 0;

        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap) {
                phaseComparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                    phaseSwaps++;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }

        cout << "The current gap size: " << gap << endl;
        cout << "The gap as a percentage of array size: " << gapPercentage << "%" << endl;
        cout << "Number of comparisons made in this phase: " << phaseComparisons << endl;
        cout << "Number of swaps made in this phase: " << phaseSwaps << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

int main() {
    int arr[] = {23, 12, 1, 5, 9, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    diminishingDistanceScanner(arr, size);

    return 0;
}
