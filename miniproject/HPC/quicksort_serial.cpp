// quicksort_serial.cpp
#include <iostream>
#include <vector>
#include "utils.h"

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int size = 10;
    std::vector<int> data = generateRandomArray(size, 100);

    std::cout << "Original array:\n";
    printArray(data);

    quicksort(data, 0, size - 1);

    std::cout << "\nSorted array:\n";
    printArray(data);

    return 0;
}
