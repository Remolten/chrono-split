//Project: Chrono Split
//Authors: Remington, Lucas, and Thomas Queenan
//Written: 09/07/16 to ??/??/??

//Discription:
// An arena based fighting game in c++ and Lua 

//Include Their Files
#include <iostream> //input output
#include <chrono> //high-res timer (chrono::high_resolution_clock::timepoint & chrono::high_resolution_clock::now())

//Include Our files
#include "../C++/Sprites/sprite.cpp" //import sprite.cpp
#include "../C++/Render/render.cpp" //import render.cpp
#include "../C++/Physics/physics.cpp" //import physics.cpp

#include <SFML/Window.hpp>

//Using
using namespace std; //for easy cout & cin

int main()
{
	sf::Window screen(sf::VideoMode(800, 600), "Chrono Split");

	cout << "Hello world" << endl;
	system("pause");
	return 0; //exited corectly
}
