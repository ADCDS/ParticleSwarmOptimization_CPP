#include "GUI.h"
#include <SFML/Graphics.hpp>
#include "PSO.h"
#include <iostream>


GUI::GUI()
{
	this->window = new sf::RenderWindow(sf::VideoMode(500, 500), "Particle Swarm Optimization (x: " + std::to_string(this->x) + ",y: " + std::to_string(this->y) + ")");
}


void GUI::display(PSO* pso)
{
	sf::Vertex x[] =
	{
		sf::Vertex(sf::Vector2f(250, 0)),
		sf::Vertex(sf::Vector2f(250, 500))
	};
	sf::Vertex y[] =
	{
		sf::Vertex(sf::Vector2f(0, 250)),
		sf::Vertex(sf::Vector2f(500, 250))
	};


	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					if (++this->x == pso->dimensions_num)
						this->x = 0;
					window->setTitle("Particle Swarm Optimization (x: " + std::to_string(this->x) + ",y: " + std::to_string(this->y) + ")");
				}
				if (event.key.code == sf::Keyboard::Y)
				{
					if (++this->y == pso->dimensions_num)
						this->y = 0;
					window->setTitle("Particle Swarm Optimization (x: " + std::to_string(this->x) + ",y: " + std::to_string(this->y) + ")");
				}
			}
		}


		


		if (pso->mtx_drawable_particles.try_lock())
		{
			window->clear();
			window->draw(x, 2, sf::Lines);
			window->draw(y, 2, sf::Lines);
			for (auto particle : pso->drawable_particles)
			{
				sf::CircleShape shape(1);
				shape.setPosition(particle.state[this->x] * 40 + 250, particle.state[this->y] * 40 + 250);
				//std::cout << particle.state[this->x] * 40 + 250 << ", " << particle.state[this->y] * 40 + 250 << "\n";
				window->draw(shape);
			}
			pso->mtx_drawable_particles.unlock();
			window->display();
		}
		
	}
}
