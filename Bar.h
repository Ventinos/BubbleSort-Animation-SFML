#pragma once
#include <SFML/Graphics.hpp>

class Bar
{
	private:
		sf::RectangleShape bar;
		int value;
		int position;
	public:
		Bar(int value, int position);
		Bar() = default;
		int getValue();
		sf::Vector2f getPosition();
		sf::RectangleShape getShape();
		void setValue(int value);
		static void fillArray(Bar* arr);
		void resetColor();
		void setColor(sf::Color c);
		void setPosition(sf::Vector2f vec);
};