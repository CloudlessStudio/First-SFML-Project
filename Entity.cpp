#include "Entity.h"
#include <random>

Entity::Entity(sf::Vector2f position) {
	_texture.loadFromFile("SpriteImages/Burger.png"); ///load image 
	_entity_sprite.setTexture(_texture);   //assign the image to sprite
	_entity_sprite.setPosition(position); //set the sprite position
	_entity_sprite.setScale(4.f, 4.f); //set the scale to 4x size
	
	
	
	
};

	void Entity::update() {
		

	};

	sf::FloatRect Entity::get_bounds() {
		return _entity_sprite.getGlobalBounds();   //get bounds of shape
	}

	float Entity::get_random_num() {   //get random location 
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dis(0.f, 1150.f);
		float num = dis(gen);

		return num;
	}


	void Entity::set_random_positon() {            //set random postion
		float x = 0.f;
		float y = 0.f;
		sf::Vector2f random_pos(x, y);
		random_pos.x = get_random_num();
		random_pos.y = get_random_num();

		_entity_sprite.setPosition(random_pos);
		

	};

	void Entity::draw(sf::RenderWindow& window) {
		window.draw(_entity_sprite);
	};

