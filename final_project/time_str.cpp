#include <fstream>
#include <string>
#include <time.h>
#include "time_str.h"


std::string now_str() {
	time_t seconds;
	seconds = time(NULL);
	tm * timeinfo;
	timeinfo = localtime(&seconds);
    return asctime(timeinfo);
}
