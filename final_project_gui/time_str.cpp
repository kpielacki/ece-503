#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "time_str_kevin_pielacki.h"


// Example function given in final project instructions with removal of print
// statements and returns "_" delimited timestamp for easier file IO
std::string now_str() {
	std::string weekday, month, day, timestamp, year, now;
	time_t seconds;
	seconds = time(NULL);
	tm * timeinfo;
	timeinfo = localtime(&seconds);

	std::istringstream ss(asctime(timeinfo));
    ss >> weekday >> month >> day >> timestamp >> year;
    now = weekday + "_" + month + "_" + day + "_" + timestamp + "_" + year;
    return now;
}
