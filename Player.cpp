#include "Player.h"

Player::Player(sf::Vector2f position) {
    _textures[0].loadFromFile("SpriteImages/FatGuy1.png");
    _textures[1].loadFromFile("SpriteImages/FatGuy2.png");
    _sprite_player.setTexture(_textures[0]);
  
	_sprite_player.setPosition(position);


}

void Player::reset() {
    _sprite_player.setPosition(600.f,600.f);
}

void Player::update() {
    _sprite_player.move(_velocity * _speed);
    static sf::Clock timer;

    if (_velocity.x ==0 && _velocity.y ==0) {    ///if not moving we are idle
        _sprite_player.setTexture(_textures[0]);
    }
    else {
        /// confusion below
        if (timer.getElapsedTime().asMilliseconds() > 200) {
            timer.restart();
            if (_sprite_player.getTexture() == &_textures[0]) { //pointer comparing memory addresses lol
                _sprite_player.setTexture(_textures[1]);
            }
            else {
                _sprite_player.setTexture(_textures[0]);
            }
        }
    }
    


    


}
sf::FloatRect Player::get_bounds() {
    return _sprite_player.getGlobalBounds();
}


void Player::draw(sf::RenderWindow& window) {
	window.draw(_sprite_player);
    //sf::err() << "Rectangle position: " << _shape.getPosition().x << ", " << _shape.getPosition().y << std::endl;
    sf::Vector2f position = _sprite_player.getPosition(); //get current position
    // Check if player is within window bounds
    if (position.x <=0) {
        _sprite_player.setPosition(0, position.y);
    }
    else if (position.x > 1072) {
        _sprite_player.setPosition(1072, position.y);
    }
    if (position.y <= 0) {
        _sprite_player.setPosition(position.x, 0);
    }
    else if (position.y > 1072) {
        _sprite_player.setPosition(position.x, 1072);
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