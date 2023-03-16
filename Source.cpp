#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "MovingBlock!");
	sf::Texture background; // declare and load bg texture
	background.loadFromFile("SpriteImages/GrassBG.png");
	sf::Sprite sprite_bg; //decalre sprite
	sprite_bg.setTexture(background);//make texture into sprite

	Player blocky(sf::Vector2f(600.f, 600.f), sf::Color::Red, sf::Color::Transparent, 3); //declare the player 
	Entity enemy(sf::Vector2f(800.f, 800.f)); //declare the enemy
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

		//if the two shapes collide move enemy away
		sf::FloatRect player_bounds = blocky.get_bounds();
		sf::FloatRect enemy_bounds = enemy.get_bounds();
		if (player_bounds.intersects(enemy_bounds)) {
			enemy.set_random_positon();
		}
		//drawing goes from first to last like a stack
		window.clear();      //refresh window
		window.draw(sprite_bg); //draw background
		blocky.draw(window);//render our player
		enemy.draw(window); //render our enemy
		blocky.update(); //update function which holds our move function
		window.display();
	}
}