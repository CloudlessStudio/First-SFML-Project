#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "MovingBlock!");
	Player blocky(sf::Vector2f(600.f, 600.f), sf::Color::Red, sf::Color::Transparent, 3); //declare the player 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			//exit on press of X
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			blocky.handle_input(event);
			
		}
		window.clear(sf::Color::Blue);
		blocky.draw(window);//render our player
		blocky.update(); //update function which holds our move function
		window.display();
	}
}