#pragma once
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include "PhysicalEvent.h"
#include "BirthdayEvent.h"
#include "ReligiousHoliday.h"
#include "Display.h"

using namespace rapidjson; 
class Calendar
{
private: 
	void sortEvents(); 
	bool swapNeeded(unsigned, unsigned); 
public:
	std::vector<Event*> eventVector; 
	std::vector<std::string> calAvailableVec; 
	std::vector<std::string> calSubscribedVec; 
	void execute(); 
};

