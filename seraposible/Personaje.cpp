#include "Personaje.h"

Personaje::Personaje()
{
    _velocidad = 4;
    _texture.loadFromFile("zombie.png");//se carga la imagen a tectura
	_sprite.setTexture(_texture); // se carga la textura al sprite
	
}

void Personaje::update()
{
    //mover personaje
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _sprite.move(0, -_velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _sprite.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _sprite.move(0, _velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _sprite.move(_velocidad, 0);
    }

    // Limitar movimiento para que no se salga de la ventana
    if (_sprite.getPosition().x < 0) { // Límite izquierdo
        _sprite.setPosition(0, _sprite.getPosition().y); // Coloca al personaje en el borde izquierdo (x = 0)
    }

    if ((_sprite.getPosition().x + _sprite.getGlobalBounds().width) > 800) { // Límite derecho
        _sprite.setPosition((800 - _sprite.getGlobalBounds().width), _sprite.getPosition().y); // Coloca al personaje en el borde derecho (x = 800)
    }

    if (_sprite.getPosition().y < 0) { // Límite superior
        _sprite.setPosition(_sprite.getPosition().x, 0); // Coloca al personaje en el borde superior (y = 0)
    }

    if ((_sprite.getPosition().y + _sprite.getGlobalBounds().height) > 600) { // Límite inferior
        _sprite.setPosition(_sprite.getPosition().x, (600 - _sprite.getGlobalBounds().height)); // Coloca al personaje en el borde inferior (y = 600)
    }

}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(_sprite, state); // donde este el taget que es el wiondow, dibuja el sprite.
}
