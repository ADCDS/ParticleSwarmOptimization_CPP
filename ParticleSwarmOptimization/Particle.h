#pragma once
#include <vector>

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

