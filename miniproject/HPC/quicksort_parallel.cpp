// quicksort_parallel.cpp
#include <mpi.h>
#include <iostream>
#include <vector>
#include <algorithm>
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

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int totalSize = 16; // Must be divisible by number of processes
    std::vector<int> globalArr;

    if (rank == 0) {
        globalArr = generateRandomArray(totalSize, 100);
        std::cout << "Unsorted array (on root): ";
        printArray(globalArr);
    }

    int localSize = totalSize / size;
    std::vector<int> localArr(localSize);

    MPI_Scatter(globalArr.data(), localSize, MPI_INT,
                localArr.data(), localSize, MPI_INT,
                0, MPI_COMM_WORLD);

    quicksort(localArr, 0, localSize - 1);

    MPI_Gather(localArr.data(), localSize, MPI_INT,
               globalArr.data(), localSize, MPI_INT,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Final sort to fully merge the partially sorted array
        quicksort(globalArr, 0, totalSize - 1);
        std::cout << "\nSorted array (after parallel + final sort): ";
        printArray(globalArr);
    }

    MPI_Finalize();
    return 0;
}
