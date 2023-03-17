#pragma once
#include <SFML/Graphics.hpp>
#ifndef PLAYER_H  /// this is so we dont re define the same header file multiple times
#define PLAYER_H /// basically if not defined define it here on line 4


class Player {
public:   //here we decalare some functions and a constructor 'Player' to be used in our player.cpp file
	Player(sf::Vector2f position); //constructor
	void update(); //update function
	void draw(sf::RenderWindow& window);  //reference to the window which we will draw this on
	void handle_input(sf::Event event);
	sf::FloatRect get_bounds();

private: //these are only for the scope of the class hence why they are private, cant be used outside of Player
	sf::RectangleShape _shape;  //
	sf::Texture _textures[2];
	sf::Sprite _sprite_player;
	sf::Vector2f _velocity = { 0.f, 0.f };
	float _speed = 1;
};
#endif PLAYER_H

