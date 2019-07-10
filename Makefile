sfml-app2: main3.o	
	g++ main3.o -o sfml-app2 -lsfml-graphics -lsfml-window -lsfml-system

main3.o: main3.cpp
	g++ -c main3.cpp

clean:
	 rm main3.o sfml-app2
