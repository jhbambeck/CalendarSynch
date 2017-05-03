#pragma once
#include "Event.h"
class ReligiousHoliday : public Event
{
private: 
	Value* holiday; 
	Value* religion; 

public:
	ReligiousHoliday::ReligiousHoliday()
		{ type = HOLIDAY; };
	virtual void populate(Value&) override;
	virtual std::string getDateString() override;
	std::string getHoliday(); 
	std::string getReligion(); 
};

