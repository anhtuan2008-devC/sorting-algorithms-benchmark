#ifndef SORTING_ALGORITHMS_H
#define ﻿SORTING_ALGORITHMS_H
#include <vector>
#include <string>

template <typename T>
struct SortingAlgorithms {
    // Nhom 1: O(n^2) - Thuat toan sap xep chon, chen, bubble, shaker, shell
    static void selectionSort(std::vector<T>& arr);
    static void insertionSort(std::vector<T>& arr);
    static void binaryInsertionSort(std::vector<T>& arr);
    static void bubbleSort(std::vector<T>& arr);
    static void shakerSort(std::vector<T>& arr);
    static void shellSort(std::vector<T>& arr);
    // Nhom 2: O(nlogn) - Thuat toan sap xep heap, merge, quick
    static void heapSort(std::vector<T>& arr);
    static void heapify(std::vector<T>& arr, int n, int i);
    static void mergeSort(std::vector<T>& arr);
    static void mergeSortManager(std::vector<T>& arr, int l, int r);
    static void merge(std::vector<T>& arr, int l, int m, int r);
    static void merge(std::vector<T>& arr, int left, int mid, int right, std::vector<T>& temp);
    static void naturalMergeSort(std::vector<T>& arr);
    static void quickSortManager(std::vector<T>& arr, int low, int high);
    static int partition(std::vector<T>& arr, int low, int high);
    static void quickSort(std::vector<T>& arr);
    static void sortOfCpp(std::vector<T>& arr);
    // Nhom 3: O(n) - Thuat toan sap xep radix, counting
    static void radixSort(std::vector<T>& arr);
    static void countingSortForRadix(std::vector<T>& arr, int n, int exp);
    static void countingSort(std::vector<T>& arr);
    static bool isNumericString(const std::string& s);
};

#endif 