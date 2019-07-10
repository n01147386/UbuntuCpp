#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


int main()
{
    
    int WIDTH = 400;
    int HEIGHT = 400;
    std::string WINDOW_TITLE = "SFML WORKS-EDIT!";



    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), WINDOW_TITLE);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
	    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
        	window.close();


        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

