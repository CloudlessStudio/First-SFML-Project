#include "GameOver.h"

void game_over(sf::RenderWindow &window) {
	sf::Texture bg;
	bg.loadFromFile("SpriteImages/GameOverArt.png");
	sf::Sprite background;
	background.setTexture(bg);
	//loading font
	sf::Font font;
	font.loadFromFile("Fonts/PixelGameFont.ttf");

	//creating text objcts
	sf::Text title("GAME OVER", font, 100);
	title.setFillColor(sf::Color::White);
	title.setPosition(300, 50);

	sf::Text play("PRESS SPACE TO PLAY", font, 80);
	play.setFillColor(sf::Color::White);
	play.setPosition(120, 800);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					return;
				}
			}
		}
		//clear window;
		window.clear();
		window.draw(background);
		window.draw(title);
		window.draw(play);
		

		window.display();
	}

}