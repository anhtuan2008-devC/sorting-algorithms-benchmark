#include <algorithm>
#include <fstream>
#include <random>
#include "text_processor.h"

std::vector<std::string> TextProcessor::readDictionary(std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> words;
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    return words;
}

void TextProcessor::cleanTextArray(std::vector<std::string>& arr) {
    for (auto& str : arr) {
        // 1: Xóa ký tự không in được
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char c) {
            return !std::isprint(c);
            }), str.end());
        // 2: Cắt khoảng trắng đầu và cuối
        size_t start = str.find_first_not_of(" \t\r\n");
        size_t end = str.find_last_not_of(" \t\r\n");
        if (start == std::string::npos) {
            str.clear();
        }
        else {
            str = str.substr(start, end - start + 1);
        }
    }
    std::shuffle(arr.begin(), arr.end(), std::default_random_engine(time(0))); // trôn dữ liệu
}