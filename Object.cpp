#include "Object.h"


Object::Object( float _x, float _y, float _width, float _height ) : 
	x		( _x ),
	y		( _y ),
	width	( _width ),
	height	( _height )
{
	shape.setPosition( x, y );
	shape.setSize( sf::Vector2f( width, height ) );
	shape.setFillColor( sf::Color( 32, 128, 255 ) );
}

void Object::Draw( sf::RenderTarget &canvas ) {
	canvas.draw( shape );
}