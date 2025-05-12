#include <random>
#include <algorithm>
#include <stack>
#include "array_generator.h"

std::random_device randomDevice;
std::mt19937_64 generator64(randomDevice());  // Bộ sinh số ngẫu nhiên 64-bit
std::mt19937 generator32(randomDevice());	// Bộ sinh số ngẫu nhiên 32-bit

// Tao mang ngau nhien voi n phan tu, moi phan tu co gia tri tu 0 den k*1000000000
template <class T>
std::vector<T> ArrayGenerator<T>::createRandomArray(const int& n, const int& k) {
    std::uniform_int_distribution<unsigned long long> uniformIntDistribution(
        0, (unsigned long long)(k) * 1000000000ULL
    );
    std::vector<T> arr(n);
    for (int i = 0; i < n; ++i) {
        if constexpr (std::is_integral_v<T>) {
            arr[i] = (T)(uniformIntDistribution(generator64));
        }
        else {
            // Xử lý mặc định nếu không phải kiểu số nguyên và cũng không phải string
            arr[i] = T();
        }
    }
    return arr;
}

// Chuyen mang sang kieu da sap xep
template <class T>
void ArrayGenerator<T>::transformSortedArray(std::vector<T>& arr) {
    std::sort(arr.begin(), arr.end());
}

// Chuyen mang sang kieu dao nguoc
template <class T>
void ArrayGenerator<T>::transformReversedArray(std::vector<T>& arr) {
    std::sort(arr.begin(), arr.end(), std::greater<T>());
}

// Chuyen mang sang kieu gan nhu da sap xep qua ti le nghich the (mac dinh 20%)
template <class T>
void ArrayGenerator<T>::transformNearlySortedArray(std::vector<T>& arr, const double& inversionRatio) {
    int n = arr.size();
    transformSortedArray(arr);
    // Tính số cặp nghịch thế
    int numInversions = (int)(n * inversionRatio / 2);
    numInversions = std::min(numInversions, n / 2);
    // Lưu danh sách các chỉ số chưa được sử dụng
    std::vector<int> unusedIndices(n);
    for (int i = 0; i < n; i++) {
        unusedIndices[i] = i;
    }
    // Thực hiện hoán đổi ngẫu nhiên từ danh sách chưa sử dụng
    for (int i = 0; i < numInversions && unusedIndices.size() >= 2; i++) {
        // Chọn hai chỉ số ngẫu nhiên từ danh sách chưa sử dụng
        std::uniform_int_distribution<int> uniformIntDistribution(0, unusedIndices.size() - 1);
        int firstRandomPos = uniformIntDistribution(generator32);
        int firstSwapIndex = unusedIndices[firstRandomPos];
        // Xóa phần tử đầu tiên
        unusedIndices.erase(unusedIndices.begin() + firstRandomPos);
        // Chọn phần tử thứ hai
        std::uniform_int_distribution<int> uniformIntDistribution2(0, unusedIndices.size() - 1);
        int secondRandomPos = uniformIntDistribution2(generator32);
        int secondSwapIndex = unusedIndices[secondRandomPos];
        // Xóa phần tử thứ hai
        unusedIndices.erase(unusedIndices.begin() + secondRandomPos);
        // Hoán đổi giá trị
        std::swap(arr[firstSwapIndex], arr[secondSwapIndex]);
    }
}