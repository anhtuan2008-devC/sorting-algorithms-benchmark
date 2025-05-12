#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H
#include <vector>

template <typename T>
struct ArrayHelper {
    static void printArray(const std::vector<T>& arr);
    static bool isSorted(const std::vector<T>& arr);
};
#endif 