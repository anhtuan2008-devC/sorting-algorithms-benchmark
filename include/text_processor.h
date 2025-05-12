#ifndef TEXT_PROCESSOR_H
#define TEXT_PROCESSOR_H
#include <vector>
#include <string>

struct TextProcessor {
    static std::vector<std::string> readDictionary(std::string filename);
    static void cleanTextArray(std::vector<std::string>& arr);
};
#endif 