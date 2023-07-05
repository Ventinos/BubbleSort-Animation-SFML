#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Bar.h"
#include "Values.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Bubble Sort");
    Bar bars[SIZE];
    Bar temp(0,0);
    bool swapped=false, sorted=false;
    
    //filling the Bar array:
    Bar::fillArray(bars);

    while (window.isOpen() && !sorted)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1 - i; j++)
            {
                //coloring:
                bars[j].setColor(sf::Color::Red);
                bars[j + 1].setColor(sf::Color::Red);
                
                //rendering:
                window.clear();
                for (int i = 0; i < SIZE; i++)
                    window.draw(bars[i].getShape());
                window.display();
                
                //sleep:
                //std::this_thread::sleep_for(std::chrono::milliseconds(2));
                
                //swapping:
                if (bars[j].getValue() > bars[j + 1].getValue())
                {
                    temp.setValue(bars[j].getValue());
                    bars[j].setValue(bars[j + 1].getValue());
                    bars[j + 1].setValue(temp.getValue());
                    swapped = true;
                }

                //rendering:
                window.clear();
                for (int i = 0; i < SIZE; i++)
                    window.draw(bars[i].getShape());
                window.display();

                //reseting colors:
                bars[j].resetColor();
                bars[j + 1].resetColor();
                
                //otimization:
                if (!swapped)
                    break;
            }
        }
        sorted = true;
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    return 0;
}