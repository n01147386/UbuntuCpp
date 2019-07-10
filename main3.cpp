#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//namespaces
using namespace std;
using namespace sf;

//function prototypes
void WriteLine(string);

//entry point
int main()
{
    
    int WIDTH = 400;
    int HEIGHT = 400;
    string WINDOW_TITLE = "WINDOW TITLE";



    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_TITLE);
   
    WriteLine("Hello World");    

    RectangleShape mainRect(Vector2f(window.getSize().x, window.getSize().y));
    mainRect.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
	    if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
        	window.close();


        }

        window.clear();
        window.draw(mainRect);
        window.display();
    }

    return 0;
}

void WriteLine(string line){
    cout << line << endl;
    	

}

