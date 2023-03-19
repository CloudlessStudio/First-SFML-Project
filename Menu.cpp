#include "Menu.h"

void menu_screen(sf::RenderWindow& window) {
	sf::Texture bg;
	bg.loadFromFile("SpriteImages/CoverArt.png");
	sf::Sprite background;
	background.setTexture(bg);
	//loading font
	sf::Font font;
	font.loadFromFile("Fonts/PixelGameFont.ttf");

	//creating text objcts
	sf::Text title("BURGER CONSUMER", font, 100);
	title.setFillColor(sf::Color::White);
	title.setPosition(120, 50);

	sf::Text guide("PRESS SPACE TO PLAY", font, 80);
	guide.setFillColor(sf::Color::White);
	guide.setPosition(120, 150);

	sf::Text credits("GAME BY Konrad Pawlikowski", font, 50);
	credits.setFillColor(sf::Color::White);
	credits.setPosition(300, 1000);

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
		window.draw(guide);
		window.draw(credits);

		window.display();
	}
}