#include <iostream>
#include <algorithm>
#include <type_traits>
#include <stack>
#include <unordered_map>
#include "sorting-algorithms.h"

// Nhom 1: O(n^2)
template <class T>
void SortingAlgorithms<T>::selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
template <class T>
void SortingAlgorithms<T>::insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <class T>
void SortingAlgorithms<T>::binaryInsertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

template <class T>
void SortingAlgorithms<T>::bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <class T>
void SortingAlgorithms<T>::shakerSort(std::vector<T>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
            }
        }
        left++;
    }
}

template <class T>
void SortingAlgorithms<T>::shellSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
// Nhom 2: O(nlogn)
template <class T>
void SortingAlgorithms<T>::heapSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template <class T>
void SortingAlgorithms<T>::heapify(std::vector<T>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <class T>
void SortingAlgorithms<T>::mergeSort(std::vector<T>& arr) {
    int n = arr.size();
    mergeSortManager(arr, 0, n - 1);
}

template <class T>
void SortingAlgorithms<T>::mergeSortManager(std::vector<T>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortManager(arr, l, m);
        mergeSortManager(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

template <class T>
void SortingAlgorithms<T>::merge(std::vector<T>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <class T>
void SortingAlgorithms<T>::merge(std::vector<T>& arr, int left, int mid, int right, std::vector<T>& temp) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

template <class T>
void SortingAlgorithms<T>::naturalMergeSort(std::vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    std::vector<T> temp(n);
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int left = 0;
        while (left < n - 1) {
            int mid = left;
            while (mid < n - 1 && arr[mid] <= arr[mid + 1]) {
                mid++;
            }
            if (mid == n - 1) {
                break;
            }
            int right = mid + 1;
            while (right < n - 1 && arr[right] <= arr[right + 1]) {
                right++;
            }
            merge(arr, left, mid, right, temp);
            sorted = false;
            left = right + 1;
        }
    }
}
// Dung stack de tranh bi tran bo nho
template <class T>
void SortingAlgorithms<T>::quickSortManager(std::vector<T>& arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push({ low, high });
    while (!stack.empty()) {
        std::pair<int, int> top = stack.top();
        stack.pop();
        int low = top.first;
        int high = top.second;
        if (low < high) {
            int pi = partition(arr, low, high);
            stack.push({ low, pi - 1 });
            stack.push({ pi + 1, high });
        }
    }
}

template <class T>
int SortingAlgorithms<T>::partition(std::vector<T>& arr, int low, int high) {
    // Sử dụng phương pháp chọn pivot giữa để tránh trường hợp xấu nhất
    int mid = low + (high - low) / 2;
    std::swap(arr[mid], arr[high]);

    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <class T>
void SortingAlgorithms<T>::quickSort(std::vector<T>& arr) {
    int n = arr.size();
    quickSortManager(arr, 0, n - 1);
}

template <class T>
void SortingAlgorithms<T>::sortOfCpp(std::vector<T>& arr) {
    std::sort(arr.begin(), arr.end());
}
// Nhom 3: O(n)
template <class T>
void SortingAlgorithms<T>::radixSort(std::vector<T>& arr) {
    int n = arr.size();
    T maxVal = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

template <class T>
void SortingAlgorithms<T>::countingSortForRadix(std::vector<T>& arr, int n, int exp) {
    std::vector<T> output(n);
    int count[10] = { 0 };
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
// counting sort thong thuong voi so phan tu <= 1000000, nguoc lai ket hop voi unordered_map 
template <class T>
void SortingAlgorithms<T>::countingSort(std::vector<T>& arr) {
    if (arr.empty()) return;
    int n = arr.size();
    // Tìm min và max để giảm kích thước mảng đếm
    T minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    T range = maxVal - minVal + 1;
    // Nếu phạm vi giá trị đủ nhỏ, dùng mảng đánh dấu
    if (range <= 1000000) {  // Giới hạn an toàn, có thể điều chỉnh
        std::vector<T> count(range, 0);
        std::vector<T> output(n);

        // Đếm số lần xuất hiện
        for (int i = 0; i < n; i++) {
            count[arr[i] - minVal]++;
        }
        // Tính tổng tích lũy
        for (T i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }
        // Xây dựng mảng output
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i] - minVal] - 1] = arr[i];
            count[arr[i] - minVal]--;
        }
        // Sao chép kết quả
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
    else {
        std::cout << "Counting sort used unorder_map\n";
        // Nếu phạm vi quá lớn, dùng unordered_map nhưng cần cẩn thận hơn
        std::vector<T> output(n);
        std::unordered_map<T, T> count;
        // Đếm số lần xuất hiện từng phần tử
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        // Tạo mảng chứa tất cả các giá trị khác nhau và sắp xếp
        std::vector<T> uniqueValues;
        for (auto& kv : count) {
            uniqueValues.push_back(kv.first);
        }
        std::sort(uniqueValues.begin(), uniqueValues.end());
        // Tính tổng tích lũy trong map
        T cumulative = 0;
        for (auto& val : uniqueValues) {
            T oldCount = count[val];
            count[val] = cumulative;
            cumulative += oldCount;
        }
        // Xây dựng mảng output
        std::unordered_map<T, T> position = count;
        for (int i = 0; i < n; i++) {
            T currentVal = arr[i];
            output[position[currentVal]] = currentVal;
            position[currentVal]++;
        }
        // Sao chép kết quả
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}
template <>
void SortingAlgorithms<std::string>::radixSort(std::vector<std::string>& arr) {
    if (arr.empty()) return;

    // Tìm độ dài chuỗi lớn nhất
    size_t maxLen = 0;
    for (const auto& str : arr) {
        maxLen = std::max(maxLen, str.length());
    }

    // Tạo mảng tạm
    std::vector<std::string> output(arr.size());

    // Sắp xếp theo từng ký tự từ cuối lên đầu (MSD Radix Sort cho chuỗi)
    for (int pos = maxLen - 1; pos >= 0; pos--) {
        // Mảng đếm cho 256 ký tự ASCII
        std::vector<int> count(256, 0);

        // Đếm số lần xuất hiện của mỗi ký tự ở vị trí pos
        for (const auto& str : arr) {
            char c = (pos < str.length()) ? str[pos] : 0; // 0 cho các chuỗi ngắn hơn
            count[(unsigned char)(c)]++;
        }

        // Tính vị trí bắt đầu của mỗi ký tự trong output
        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }

        // Xây dựng mảng output
        for (int i = arr.size() - 1; i >= 0; i--) {
            char c = (pos < arr[i].length()) ? arr[i][pos] : 0;
            output[--count[(unsigned char)(c)]] = arr[i];
        }

        // Sao chép output vào arr
        arr = output;
    }
}

// Kiểm tra chuỗi có phải toàn ký tự số không
bool SortingAlgorithms<std::string>::isNumericString(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

template <>
void SortingAlgorithms<std::string>::countingSort(std::vector<std::string>& arr) {
    if (arr.empty()) return;
    int n = arr.size();

    std::cout << "Counting sort for string used unordered_map\n";

    // Xác định xem toàn bộ chuỗi có phải số không
    bool allNumeric = std::all_of(arr.begin(), arr.end(), isNumericString);

    // unordered_map để đếm tần suất xuất hiện
    std::unordered_map<std::string, int> count;
    for (const auto& val : arr) {
        count[val]++;
    }

    // Tạo mảng các giá trị duy nhất
    std::vector<std::string> uniqueValues;
    for (auto& kv : count) {
        uniqueValues.push_back(kv.first);
    }

    // Sắp xếp các giá trị
    if (allNumeric) {
        // Nếu toàn số, sắp theo độ dài rồi từ điển
        std::sort(uniqueValues.begin(), uniqueValues.end(), [](const std::string& a, const std::string& b) {
            if (a.length() != b.length()) return a.length() < b.length();
            return a < b;
            });
    }
    else {
        // Nếu chứa chữ cái, sắp theo thứ tự từ điển bình thường
        std::sort(uniqueValues.begin(), uniqueValues.end());
    }

    // Tính tổng tích lũy
    int cumulative = 0;
    std::unordered_map<std::string, int> position;
    for (const auto& val : uniqueValues) {
        position[val] = cumulative;
        cumulative += count[val];
    }

    // Xây dựng mảng output
    std::vector<std::string> output(n);
    for (int i = 0; i < n; i++) {
        std::string currentVal = arr[i];
        output[position[currentVal]] = currentVal;
        position[currentVal]++;
    }

    // Gán kết quả trở lại
    arr = output;
}