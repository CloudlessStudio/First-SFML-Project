#pragma once
#include <SFML/Graphics.hpp>
#ifndef ENTITY_H
#define ENTITY_H
class Entity {
public:
	Entity(sf::Vector2f position);
	void update();
	void reset();
	void draw(sf::RenderWindow& window);
	void set_random_positon();
	sf::FloatRect get_bounds();
	
	
	
private:
	sf::Texture _texture;
	sf::Sprite _entity_sprite;
	float get_random_num();
	

};



#endif
