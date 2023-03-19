#include "Entity.h"
#include <random>


Entity::Entity(sf::Vector2f position) {
	_texture.loadFromFile("SpriteImages/Burger.png"); ///load image 
	_entity_sprite.setTexture(_texture);   //assign the image to sprite
	_entity_sprite.setPosition(position); //set the sprite position
	_entity_sprite.setScale(4.f, 4.f); //set the scale to 4x size
	life = 1;

	
	
	
	
};

	void Entity::reset() {
		_entity_sprite.setScale(4.f, 4.f);
		life = 1;
		}
	void Entity::update() {
		sf::Vector2f curr_scale = _entity_sprite.getScale();
		sf::Vector2f curr_pos = _entity_sprite.getPosition();
		
		//sf::err() << "Scale is: " << curr_scale.x << ", " << curr_scale.y << std::endl;
		if (curr_scale.x <= 0 || curr_scale.y <= 0 ) {
			
			life = 0;
			
			
		}
		else {
			_entity_sprite.setScale(curr_scale.x - .0022, curr_scale.y - .0022);
		}
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

