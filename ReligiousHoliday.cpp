#include "stdafx.h"
#include "ReligiousHoliday.h"

void ReligiousHoliday::populate(Value& anEvent)
{
	day = &anEvent["day"];
	month = &anEvent["month"];
	holiday = &anEvent["holiday"];
	religion = &anEvent["religion"];
}

std::string ReligiousHoliday::getDateString()
{
	std::string infoString;
	infoString.append(std::to_string(getMonth()));
	infoString.append("/");
	infoString.append(std::to_string(getDay()));
	return infoString;
}

std::string ReligiousHoliday::getHoliday()
{
	std::string holidayString; 
	holidayString = holiday->GetString(); 
	return holidayString; 
}

std::string ReligiousHoliday::getReligion()
{
	std::string religionString; 
	religionString = religion->GetString(); 
	return religionString; 
}