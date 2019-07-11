#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <time.h>

//namespaces
using namespace std;
using namespace sf;

//function prototypes
void WriteLine(string); //console printout

RectangleShape CreateControl(Vector2f,Vector2f, Color, Color);




// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}




//entry point
int main()
{
    
    //Window properties
    int WIDTH = 800;
    int HEIGHT = 800;
    string WINDOW_TITLE = "My Title";
    Color COLOR_BACKGROUND = Color::White;
    Color COLOR_BORDER = Color::White;
    
    //Font properties
    string FONT_FILE = "FreeMono.ttf";
    int FONT_SIZE = 14;
    int FONT_MARGIN_X = 20;
    int FONT_MARGIN_Y = 2;
    Color FONT_COLOR = Color::Black;

    RenderWindow window(VideoMode(WIDTH, HEIGHT), WINDOW_TITLE);
   
    RectangleShape mainRect = CreateControl(Vector2f(0,0), Vector2f(window.getSize().x, window.getSize().y),
COLOR_BACKGROUND,COLOR_BORDER);

    RectangleShape subRect = CreateControl(Vector2f(50,50), Vector2f(100,25), 
Color::White, Color::Black);
    
    Font font;
    
    if (!font.loadFromFile(FONT_FILE)){ 
	//error
	cout << "Couldn't load font!" << endl;
	return 250;
    }

    Text text;
    text.setFont(font);
    text.setString("button1");
    text.setCharacterSize(FONT_SIZE); //in pixels
    text.setColor(FONT_COLOR);
    text.setPosition(subRect.getPosition().x + FONT_MARGIN_X,subRect.getPosition().y + FONT_MARGIN_Y);


    //application loop
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
	    if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
        	window.close();
	    if (event.type == Event::MouseButtonPressed){
	    	if (event.mouseButton.button == sf::Mouse::Left){
		    if (subRect.getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) {
                        std::cout << "Button pressed" << std::endl;
                    }
		}
              
	    }

	    if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::F12)){
    		sf::Image screenshot = window.capture(); 		 
		screenshot.saveToFile("screenshots/" + currentDateTime() + ".png");
	    } 



        }

        window.clear();
        window.draw(mainRect);
	window.draw(subRect);
	window.draw(text);
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



