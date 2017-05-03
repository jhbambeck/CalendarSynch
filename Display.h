#pragma once
#include <iostream>
#include <vector>
#include "PhysicalEvent.h"
#include "BirthdayEvent.h"
#include "ReligiousHoliday.h"
#include <SFML/Graphics.hpp>

class Display
{
private: 
	sf::RenderWindow window;
public:
	void screen2(std::vector<Event*>&);
	void screen1(std::vector<std::string>&, std::vector<std::string>&);
	Display()
		{ window.create(sf::VideoMode(512, 512), "CalendarSynch", sf::Style::Close | sf::Style::Titlebar); }

};

