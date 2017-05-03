#include "stdafx.h"
#include "PhysicalEvent.h"

void PhysicalEvent::populate(Value& anEvent)
{
	day = &anEvent["day"];
	month = &anEvent["month"];
	title = &anEvent["title"];
	location = &anEvent["location"];
}

std::string PhysicalEvent::getTitle()
{
	std::string titleString; 
	titleString = title->GetString(); 
	return titleString; 
}

std::string PhysicalEvent::getLocation()
{
	std::string locationString; 
	locationString = location->GetString(); 
	return locationString; 
}

std::string PhysicalEvent::getDateString()
{
	std::string infoString; 
	infoString.append(std::to_string(getMonth()));
	infoString.append("/");
	infoString.append(std::to_string(getDay()));
	return infoString; 
}