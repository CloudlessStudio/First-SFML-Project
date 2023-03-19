#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Entity.h"
#include "Menu.h"
#include "GameOver.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1200, 1200), "BurgerConsumer");
	sf::Texture background; // declare and load bg texture
	background.loadFromFile("SpriteImages/GrassBG.png");
	sf::Sprite sprite_bg; //decalre sprite
	sprite_bg.setTexture(background);//make texture into sprite
	//sounds --------------------
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Sounds/Eat.ogg")) {
		return -1;
	}
	
	sf::Sound chomp;
	chomp.setBuffer(buffer);
	// text ------------------------------------
	sf::Font font;
	font.loadFromFile("Fonts/PixelGameFont.ttf");
	sf::Text burger("BURGERS EATEN:", font, 55);
	burger.setFillColor(sf::Color::White);
	burger.setPosition(50, 50);
	
	int burger_count = 0;
	sf::Text count(std::to_string(burger_count), font, 55);
	count.setFillColor(sf::Color::White);
	count.setPosition(550, 50);

	//characters------------------------------------
	Player blocky(sf::Vector2f(600.f, 600.f)); //declare the player 
	Entity enemy(sf::Vector2f(800.f, 800.f)); //declare the enemy


	enum gameState {
		MENU,
		PLAY,
		GAMEOVER
	};

	gameState state = gameState::MENU;
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

		if (state == gameState::MENU) {
			menu_screen(window);
			state = gameState::PLAY;
		}
		else if (state == gameState::PLAY) {

			
			//if the two shapes collide move enemy away
			sf::FloatRect player_bounds = blocky.get_bounds();
			sf::FloatRect enemy_bounds = enemy.get_bounds();
			if (player_bounds.intersects(enemy_bounds)) {
				burger_count++;
				chomp.play();
				enemy.set_random_positon();
				enemy.reset();
				count.setString(std::to_string(burger_count));

			}
			if (enemy.life == 0) {
				state = gameState::GAMEOVER;
				enemy.reset();
				
			}
			//drawing goes from first to last like a stack
			window.clear();      //refresh window
			window.draw(sprite_bg); //draw background
			blocky.draw(window);//render our player
			enemy.draw(window); //render our enemy
			window.draw(burger);
			window.draw(count);
			enemy.update(); //updates enemy 
			blocky.update(); //update function which holds our move function
		}
		else if (state == gameState::GAMEOVER) {
			game_over(window);
			state = gameState::MENU;
			burger_count = 0;
			count.setString(std::to_string(burger_count));
			blocky.reset();
		}
		window.display();
	}
}