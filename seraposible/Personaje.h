#pragma once
#include <SFML/Graphics.hpp>
class Personaje:public sf::Drawable
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _velocidad;

public:
	Personaje(); //constructor

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; // metodo polimorfico de la clase drawable que me permite indicar como dibujar el personaje

};

