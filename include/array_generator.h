#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H
#include <vector>
enum class arrayInputType {
    random,
    sorted,
    reversed,
    nearlySorted
};

template <typename T>
struct ArrayGenerator {
    static std::vector<T> createRandomArray(const int& n, const int& k);
    static void transformSortedArray(std::vector<T>& arr);
    static void transformReversedArray(std::vector<T>& arr);
    static void transformNearlySortedArray(std::vector<T>& arr, const double& inversionRatio = 0.2);
};
#endif 