#include "time_utils.h"

// Chuyen doi thoi gian tu microseconds sang milliseconds
long long Timer::microsecondsToMilliseconds(const long long& microseconds) {
    return (microseconds + 500) / 1000;
}