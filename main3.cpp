#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//namespaces
using namespace std;
using namespace sf;

//function prototypes
void WriteLine(string); //console printout

RectangleShape CreateControl(Vector2f,Vector2f, Color, Color);

//entry point
int main()
{
    
    int WIDTH = 400;
    int HEIGHT = 400;
    string WINDOW_TITLE = "WINDOW TITLE";



    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_TITLE);
   
    WriteLine("Hello World");    

    RectangleShape mainRect = CreateControl(Vector2f(0,0), Vector2f(window.getSize().x, window.getSize().y),
Color::White,Color::White);

    RectangleShape subRect = CreateControl(Vector2f(50,50), Vector2f(100,25), 
Color::White, Color::Black);

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
	window.draw(subRect);
        window.display();
    }

    return 0;
}

void WriteLine(string line){
    cout << line << endl;
}

RectangleShape CreateControl(Vector2f v2f_loc, Vector2f v2f_size, Color bgColor, Color outlineColor){
    
	RectangleShape rect;
	rect.setSize(v2f_size);
	rect.setPosition(v2f_loc);
	rect.setFillColor(bgColor);
	rect.setOutlineColor(outlineColor);
	rect.setOutlineThickness(1.f);
	
	return rect;
}
