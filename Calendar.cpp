#include "stdafx.h"
#include "Calendar.h"

using namespace rapidjson; 

void Calendar::execute()
{
	// 1. Parse a JSON string into DOM.
	std::ifstream calendarsDoc;
	calendarsDoc.open("calendars.txt");
	if (!calendarsDoc) std::cout << "Cannot open file" << std::endl;
	std::string calendars;
	std::string wholeCalendars; 
	while (!calendarsDoc.eof())
	{
		getline(calendarsDoc, calendars);
		wholeCalendars.append(calendars);
	}
	const char* json = wholeCalendars.c_str();
	Document calendarsDom;
	calendarsDom.Parse(json);
	
	// 2. Modify it by DOM. 
	Value& calendarArr = calendarsDom["calendars"];
	assert(calendarArr.IsArray());
	SizeType calendarSize = calendarArr.Size(); 
	int csz = static_cast<int>(calendarSize);

	//fill calendarsAvailableVector
	std::string calendarName; 
	for (int i = 0; i < csz; i++)
	{
		 Value& nameValue = calendarArr[i]["name"];
		 calendarName = nameValue.GetString(); 
		 calAvailableVec.push_back(calendarName);
	}

	Display disp;
	disp.screen1(calAvailableVec, calSubscribedVec);

	bool processCal; 
	for (int i = 0; i < csz; i++)
	{
		Value& calNameVal = calendarArr[i]["name"];
		std::string calName = calNameVal.GetString();
		processCal = false;
		for (std::vector<std::string>::iterator itr = calSubscribedVec.begin();
			itr != calSubscribedVec.end(); ++itr)
		{
			if (calName == *(itr)) processCal = true; 
		}
		if (processCal)
		{
			Value& eventArr = calendarArr[i]["events"];
			assert(eventArr.IsArray());
			SizeType eventSize = eventArr.Size();
			int esz = static_cast<int>(eventSize);
			for (int j = 0; j < esz; j++)
			{
				Value& anEvent = eventArr[j];
				std::string eventType = anEvent["event type"].GetString();
				if (eventType == "physical")
				{
					Event* evnt = new PhysicalEvent;
					evnt->populate(anEvent);
					eventVector.push_back(evnt);
				}
				else if (eventType == "birthday")
				{

					Event* evnt = new BirthdayEvent;
					evnt->populate(anEvent);
					eventVector.push_back(evnt);
				}
				else if (eventType == "religious holiday")
				{
					Event* evnt = new ReligiousHoliday;
					evnt->populate(anEvent);
					eventVector.push_back(evnt);
				}
				else std::cout << "Error: unrecognized \"event type\"" << std::endl;
			}//event loop
		}//processCal
	}//calendar loop

	sortEvents(); 
	disp.screen2(eventVector);
}

void Calendar::sortEvents()
{
	Event * temp;
	for (unsigned i = 0; i < eventVector.size(); ++i)
	{
		for (unsigned j = eventVector.size() - 1; j > i;  --j)
		{
			if (swapNeeded(j, j - 1))
			{
				temp = eventVector[j];
				eventVector[j] = eventVector[j - 1];
				eventVector[j - 1] = temp; 
			}
		}
	}
}

bool Calendar::swapNeeded(unsigned second, unsigned first)
{
	int monthSecond = eventVector[second]->getMonth(); 
	int monthFirst = eventVector[first]->getMonth();
	if (monthFirst > monthSecond) return true; 
	else if (monthFirst < monthSecond) return false; 
	else
	{
		int daySecond = eventVector[second]->getDay(); 
		int dayFirst = eventVector[first]->getDay(); 
		if (dayFirst > daySecond) return true; 
		else return false; 
	}
}