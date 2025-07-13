#include <iostream>
#include <vector>
#include "heap.h" // Assumes heapSort(std::vector<int>&) is defined here

int main() {
    std::vector<int> data = {34, 7, 23, 32, 5, 62, 78, 1, 45, 19,1,1,-1,34,99999,67};

    std::cout << "Original vector: ";
    for (int n : data) std::cout << n << " ";
    std::cout << std::endl;

    heapsort(data);

    std::cout << "Sorted vector: ";
    for (int n : data) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}