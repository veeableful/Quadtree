// QuadtreeSimple.cpp : Demonstrates the use of Quadtree using SFML
//

#include "Quadtree.h"
#include "Object.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>

int main()
{
	using namespace std;

	sf::RenderWindow app( sf::VideoMode( 800, 600, 32 ), "Quadtree" );
	app.setFramerateLimit( 60 );

	sf::Font font;
	font.loadFromFile( "DroidSans.ttf" );

	Quadtree quadtree( 0.0f, 0.0f, 800.0f, 600.0f, 0, 3 );
	quadtree.SetFont( font );

	vector<Object> objects;

	while( app.isOpen() ) {
		sf::Event event;
		sf::Vector2i mousePosition = sf::Mouse::getPosition( app );
		while( app.pollEvent( event ) ) {
			if ( event.type == sf::Event::KeyPressed ) {
				if ( event.key.code == sf::Keyboard::Escape ) {
					app.close();
				}
			}
			if ( event.type == sf::Event::MouseButtonPressed ) {
				objects.push_back( Object( mousePosition.x, mousePosition.y, 32, 32 ) );
			}
		}
		app.clear();

		for ( int n = 0; n < objects.size(); ++n ) {
			quadtree.AddObject( &objects[n] );
			objects[n].Draw( app );
		}
		quadtree.Draw( app );

		vector<Object*> returnObjects = quadtree.GetObjectsAt( mousePosition.x, mousePosition.y );
		cout << returnObjects.size() << endl;
		quadtree.Clear();

		app.display();
	}

	return 0;
}