#include "Particle.h"
#include <string>


Particle::Particle()
{
}


Particle::~Particle()
{
}

std::string Particle::to_string() const
{
	std::string res = "{";
	for (auto&& value : state)
	{
		res += std::to_string(value) + ",";
	}
	return res + "}";

}
