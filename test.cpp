#include <SFML/Graphics.hpp>

void popup()
{
    sf::RenderWindow w2(sf::VideoMode(200, 200), "Sub window");

    while (w2.isOpen())
    {
        sf::Event event;
        while (w2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w2.close();
        }

        w2.clear(sf::Color::Green);
        w2.display();
    }
}

int main()
{
    sf::RenderWindow w1(sf::VideoMode(800, 600), "Main window");

    while (w1.isOpen())
    {
        sf::Event event;
        while (w1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w1.close();
            if (event.type == sf::Event::MouseButtonPressed)
                popup();
        }

        w1.clear(sf::Color::Blue);
        w1.display();
    }

    return EXIT_SUCCESS;
}
