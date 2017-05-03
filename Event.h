#pragma once
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/pointer.h"
#include <string>

using namespace rapidjson; 

enum { PHYSICAL, BIRTHDAY, HOLIDAY };

class Event {
protected: 
	Value* day; 
	Value* month; 
public:
	int getDay()
		{ return day->GetInt(); }
	int getMonth()
		{ return month->GetInt(); };
	virtual void populate(Value&) = 0; 
	virtual std::string getDateString() = 0; 
	int type; 
};

