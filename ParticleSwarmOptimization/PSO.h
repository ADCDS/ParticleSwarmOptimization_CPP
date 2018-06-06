#ifndef PSO_H
#define PSO_H

#include <vector>
#include <mutex>

#include "Particle.h"

class PSO
{
public:
	int dimensions_num;
	int particle_num;
	int max_it;
	double max_velocity;
	std::vector<std::pair<double /*min*/, double /*max*/>>* dimensions_limits;
	std::vector<Particle> particles;

	std::mutex mtx_drawable_particles;
	std::vector<Particle> drawable_particles;
	


	PSO(int dimensions_num, int particle_num, int max_it, double max_velocity, std::vector<std::pair<double, double>>* dimensions_limits);

	Particle* run();
	double eval(std::vector<double>* p);

	~PSO();
};

#endif