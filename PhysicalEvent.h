#pragma once
#include "Event.h"
class PhysicalEvent : public Event
{
private: 
	Value* location; 
	Value* title; 
public:
	PhysicalEvent::PhysicalEvent()
		{ type = PHYSICAL; };
	virtual void populate(Value&) override;
	virtual std::string getDateString() override;
	std::string getTitle(); 
	std::string getLocation();  
};

