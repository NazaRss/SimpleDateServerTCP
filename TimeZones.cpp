#include "stdafx.h"
#include "dateserver.h"

std::string TimeZones::getDateAndTime(std::string inputString) 
{ 
	using namespace std;

	boost::to_upper(inputString);

	int TimeFromTimeZone = TimeZones::getTimeFromTimeZone(inputString);

	if (TimeFromTimeZone == 1001) {

		inputString = "Vveden nevernuy zapros, dolhsno butb naprimer: MSK, BST. \n Good Bye!";

		return inputString;
	} else {

		int koefTime = TimeFromTimeZone;

		if (koefTime < localTimeZone) {
			koefTime = (((localTimeZone) - (koefTime)) * 3600) * (-1); 
		} else {
			koefTime = (((koefTime) - (localTimeZone)) * 3600);
		}

		time_t now = time(0) + koefTime;
		char   buf[80];
		char   buf2[80];

		strftime(buf, sizeof(buf), "%a %b %d %H:%M:%S ", std::localtime(&now));
		strftime(buf2, sizeof(buf2), " %Y", std::localtime(&now));

		string outputString;
		outputString += buf + inputString + buf2;

		return outputString;
	}
}


int TimeZones::getTimeFromTimeZone(std::string inputString) 
{
	using namespace std;

	const int ERROR_TIMEZONE_NOT_FOUND = 1001;
	
	map <string,int> mapTimeZones;

		 mapTimeZones ["BST"] = +1;
		 mapTimeZones ["AEST"] = +10;
		 mapTimeZones ["AKT"] = -9;
		 mapTimeZones ["ART"] = -3;
		 mapTimeZones ["AST"] = -3;
		 mapTimeZones ["AWST"] = +8;
		 mapTimeZones ["BDT"] = +6;
		 mapTimeZones ["BTT"] = +6;
		 mapTimeZones ["CAT"] = +2;
		 mapTimeZones ["CET"] = +1;
		 mapTimeZones ["CST"] = -6;
		 mapTimeZones ["CXT"] = +7;
		 mapTimeZones ["CHT"] = -4;
		 mapTimeZones ["EAT"] = +3;
		 mapTimeZones ["EET"] = +2;
		 mapTimeZones ["EST"] = -5;
		 mapTimeZones ["FET"] = +3;
		 mapTimeZones ["GALT"] = +6;
		 mapTimeZones ["GMT"] = 0;
		 mapTimeZones ["HAST"] = -10;
		 mapTimeZones ["HKT"] = +8;
		 mapTimeZones ["IST"] = +2;
		 mapTimeZones ["JST"] = +9;
		 mapTimeZones ["MT"] = -7;
		 mapTimeZones ["MSK"] = +3;
		 mapTimeZones ["NFT"] = +11;
		 mapTimeZones ["PET"] = -5;
		 mapTimeZones ["PHT"] = +8;
		 mapTimeZones ["PKT"] = +5;
		 mapTimeZones ["PMST"] = -3;
		 mapTimeZones ["PST"] = -8;
		 mapTimeZones ["SST"] = +8;
		 mapTimeZones ["ST"] = -11;
		 mapTimeZones ["THA"] = +7;
		 mapTimeZones ["UTC"] = 0;
		 mapTimeZones ["WAT"] = +1;
		 mapTimeZones ["WET"] = 0;

	if ( mapTimeZones.find(inputString) == mapTimeZones.end() ) {
		
		return ERROR_TIMEZONE_NOT_FOUND;
	} else {
		cout << "The choice a zone: " << mapTimeZones[inputString] << endl;
		return mapTimeZones[inputString];
	}

	return ERROR_TIMEZONE_NOT_FOUND;
}