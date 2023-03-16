#include "Player.h"

Player::Player(sf::Vector2f position, sf::Color outline, sf::Color fill, float thickness) {
	_shape.setSize(sf::Vector2f( 100.f,100.f ));
	_shape.setPosition(position);
	_shape.setFillColor(fill);
	_shape.setOutlineColor(outline);
	_shape.setOutlineThickness(thickness);

}

void Player::update() {
	_shape.move(_velocity * _speed);
    


}
sf::FloatRect Player::get_bounds() {
    return _shape.getGlobalBounds();
}


void Player::draw(sf::RenderWindow& window) {
	window.draw(_shape);
    //sf::err() << "Rectangle position: " << _shape.getPosition().x << ", " << _shape.getPosition().y << std::endl;
    sf::Vector2f position = _shape.getPosition(); //get current position
    // Check if player is within window bounds
    if (position.x < 3) {
        _shape.setPosition(3, position.y);
    }
    else if (position.x > 1097) {
        _shape.setPosition(1097, position.y);
    }
    if (position.y < 3) {
        _shape.setPosition(position.x, 3);
    }
    else if (position.y > 1098) {
        _shape.setPosition(position.x, 1097);
    }

}

void Player::handle_input(sf::Event event) {
    


    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A)
            _velocity.x = -1.f;
        if (event.key.code == sf::Keyboard::D)
            _velocity.x = 1.f;
        if (event.key.code == sf::Keyboard::W)
            _velocity.y = -1.f;
        if (event.key.code == sf::Keyboard::S)
            _velocity.y = 1.f;
    }

    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D )
            _velocity.x = 0.f;
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)
            _velocity.y = 0.f;
    }
    
}