#include "stdafx.h"
#include "BirthdayEvent.h"


void BirthdayEvent::populate(Value& anEvent)
{
	day = &anEvent["day"];
	month = &anEvent["month"];
	name = &anEvent["name"];
}

std::string BirthdayEvent::getName()
{
	std::string nameString; 
	nameString = name->GetString(); 
	return nameString; 
}

std::string BirthdayEvent::getDateString()
{
	std::string infoString; 
	infoString.append(std::to_string(getMonth()));
	infoString.append("/");
	infoString.append(std::to_string(getDay()));
	return infoString; 
}