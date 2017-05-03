#pragma once
#include "Event.h"
class BirthdayEvent : public Event
{
private:
	Value* name; 
public:
	BirthdayEvent::BirthdayEvent()
		{ type = BIRTHDAY; };
	virtual void populate(Value&) override;
	virtual std::string getDateString() override; 
	std::string getName();
};

