#include "stdafx.h"
#include "Display.h"

void Display::screen1(std::vector<std::string>& calAvailableVec, 
	std::vector<std::string>& calSubscribedVec)
{
	sf::RectangleShape background(sf::Vector2f(512.0f, 512.0f));
	background.setFillColor(sf::Color::White);
	background.setPosition(0, 0);
	window.draw(background);

	sf::RectangleShape rectangle(sf::Vector2f(512.0f, 51.2f));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(5.0);
	rectangle.setPosition(0, 51.2 * 9);
	window.draw(rectangle);

	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(0, 0);

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text calText;
	calText.setFont(font);
	calText.setCharacterSize(25);
	calText.setString("Synch");
	calText.setPosition(230, 51.2 * 9 + 5);
	window.draw(calText);

	calText.setPosition(0, 0);

	float currentY = 0;
	float increment = 51.2;
	float calAdjust = 5;

	std::string aCalendarName; 
	for (std::vector<std::string>::iterator itr = calAvailableVec.begin(); itr != calAvailableVec.end();
		itr++)
	{
		rectangle.setPosition(0, currentY);
		window.draw(rectangle);
		aCalendarName = *(itr);
		calText.setString(aCalendarName);
		calText.setPosition(0, currentY + calAdjust);
		window.draw(calText);
		currentY += increment;
		std::cout << aCalendarName << std::endl; 
	}

	sf::Vector2u windowSize = window.getSize();
	sf::Texture screenTex; 
	screenTex.create(windowSize.x, windowSize.y);
	screenTex.update(window);
	sf::Sprite screenSprite; 
	screenSprite.setTexture(screenTex);
	window.display();

	rectangle.setFillColor(sf::Color::Green);
	
	sf::Event sfevnt; 
	bool cont = true;
	while (window.isOpen() && cont)
	{
		while (window.pollEvent(sfevnt) && cont)
		{
			switch (sfevnt.type)
			{
			case (sf::Event::Closed):
				window.close();
				break;

			case (sf::Event::MouseButtonPressed):
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				int calInt = (static_cast<int>(mousePos.y / 51.2) + 1);
				std::cout << calInt << std::endl;
				if (calInt == 10) cont = false;
				else if (calInt <= calAvailableVec.size())
				{
					window.draw(screenSprite);
					std::string calendarName = calAvailableVec[calInt - 1];
					std::cout << "here" << std::endl;
					calSubscribedVec.push_back(calendarName);
					rectangle.setPosition(0, (calInt - 1)* increment);
					window.draw(rectangle);
					calText.setString(calendarName);
					calText.setPosition(0, (calInt - 1) * increment + 5);
					window.draw(calText);
					screenTex.update(window);
					window.display();
				}
				break; 
			}
		}
	}
	window.clear(); 
}

void Display::screen2(std::vector<Event*>& eventVector)
{
	sf::RectangleShape background(sf::Vector2f(512.0f, 512.0f));
	background.setFillColor(sf::Color::White);
	background.setPosition(0, 0);
	window.draw(background); 

	sf::RectangleShape rectangle(sf::Vector2f(512.0f, 51.2f));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(5.0);
	rectangle.setPosition(0, 0);

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text infoText;
	infoText.setFont(font);
	infoText.setCharacterSize(25);
	infoText.setPosition(0, 0);

	float currentY = 0;
	float increment = 51.2;
	float infoAdjust = 5; 

	PhysicalEvent* pevnt; 
	BirthdayEvent* bevnt; 
	ReligiousHoliday* hevnt; 

	std::string infoString;
	for (std::vector<Event*>::iterator itr = eventVector.begin(); itr != eventVector.end(); ++itr)
	{
		infoString = "";
		switch ((*itr)->type)
		{
		case (PHYSICAL):

			pevnt = static_cast<PhysicalEvent*>(*itr);
			infoString.append(pevnt->getDateString());
			infoString.append("    ");
			infoString.append(pevnt->getTitle());
			infoString.append("    ");
			infoString.append(pevnt->getLocation());
			infoText.setString(infoString);
			infoText.setPosition(0, currentY + infoAdjust);
			window.draw(rectangle);
			window.draw(infoText);
			currentY += increment;
			break;

		case (BIRTHDAY):
			bevnt = static_cast<BirthdayEvent*>(*itr);
			infoString.append(bevnt->getDateString());
			infoString.append("    ");
			infoString.append(bevnt->getName());
			infoString.append("'s Birthday");
			infoText.setString(infoString);
			infoText.setPosition(0, currentY + infoAdjust);
			window.draw(rectangle);
			window.draw(infoText);
			currentY += increment;
			break;
		
		case (HOLIDAY):
			hevnt = static_cast<ReligiousHoliday*>(*itr);
			infoString.append(hevnt->getDateString());
			infoString.append("    ");
			infoString.append(hevnt->getHoliday());
			infoString.append("    religion: ");
			infoString.append(hevnt->getReligion());
			infoText.setString(infoString);
			infoText.setPosition(0, currentY + infoAdjust);
			window.draw(rectangle);
			window.draw(infoText);
			currentY += increment;
			break;
		}
		rectangle.setPosition(0, currentY);
		std::cout << infoString << std::endl;
	}
	window.display(); 
	while (window.isOpen())
	{
		sf::Event sfevnt;
		while (window.pollEvent(sfevnt))
		{
			switch (sfevnt.type)
			{
			case (sf::Event::Closed):
				window.close();
				break; 
			}
		}//pollevent
	}//window
}

