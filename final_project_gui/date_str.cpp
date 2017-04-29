#include <fstream>
#include <string>
#include <ctime>
#include "date_str.h"


std::string today_str() {
    char buffer[11];
    std::string date_str;
    time_t now = time(0);

    tm *lt = localtime(&now);
    sprintf(buffer, "%04d-%02d-%02d",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday);
    date_str = std::string(buffer);

    return date_str;
}
