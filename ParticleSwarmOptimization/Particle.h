#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <string>
class Particle
{
public:
	std::vector<double> state;
	std::vector<double> best_known_state;
	std::vector<double> v;

	Particle();
	~Particle();


	std::string to_string() const;
};

#endif