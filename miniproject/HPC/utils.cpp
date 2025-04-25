// utils.cpp
#include "utils.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomArray(int size, int maxVal) {
    std::vector<int> arr(size);
    srand(time(0));
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % maxVal;
    return arr;
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
