#include "array_helper.h"
#include <iostream>

template <class T>
void ArrayHelper<T>::printArray(const std::vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <class T>
bool ArrayHelper<T>::isSorted(const std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}