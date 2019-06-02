#include "dateserver.h"

class TimeZones
{ 

public:
	static const int localTimeZone = 8;

	static std::string getDateAndTime(std::string str);
	static int getTimeFromTimeZone(std::string str); 

};