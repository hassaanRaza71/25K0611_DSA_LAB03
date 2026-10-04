#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionArmSorter(int arr[], int size) {
    int totalShiftDistance = 0;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        int currentShifts = 0;

        cout << "\nProcessing key: " << key << endl;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            currentShifts++;
        }
        arr[j + 1] = key;
        totalShiftDistance += currentShifts;

        if (currentShifts == 0) {
            cout << "No shift required" << endl;
        } else {
            cout << "Positions shifted: " << currentShifts << endl;
        }

        cout << "Current array state: ";
        printArray(arr, size);
    }

    cout << "\nTotal shift distance (sum of all shifts): " << totalShiftDistance << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    insertionArmSorter(arr, size);

    return 0;
}
