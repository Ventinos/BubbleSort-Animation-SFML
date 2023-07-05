#include "Bar.h"
#include "Values.h"

Bar::Bar(int value, int position)
{
	bar.setFillColor(sf::Color::White);
	bar.setPosition(sf::Vector2f((float)position * ((WINDOW_SIZE / SIZE) + 1), (float)(WINDOW_SIZE - value)));
	bar.setSize(sf::Vector2f((float)(WINDOW_SIZE / SIZE), (float)value));
	this->value = value;
	this->position = position;
}

sf::Vector2f Bar::getPosition()
{
	return bar.getPosition();
}

int Bar::getValue()
{
	return value;
}

sf::RectangleShape Bar::getShape()
{
	return bar;
}

void Bar::setValue(int value)
{
	bar.setSize(sf::Vector2f((float)(WINDOW_SIZE / SIZE), (float)value));
	bar.setPosition(sf::Vector2f((float)position * ((WINDOW_SIZE / SIZE) + 1), (float)(WINDOW_SIZE - value)));
	this->value = value;
}

void Bar::resetColor()
{
	bar.setFillColor(sf::Color::White);
}

void Bar::setColor(sf::Color c)
{
	bar.setFillColor(c);
}

void Bar::setPosition(sf::Vector2f vec)
{
	bar.setPosition(vec);
	position =(int)vec.x;
}

void Bar::fillArray(Bar* arr)
{
	int value = 0;
	std::srand(std::time(NULL));
	for (int i =0; i<SIZE; i++)
	{
		value = std::rand() % WINDOW_SIZE + 1;
		arr[i] = Bar(value,i);
	}
	return;
}