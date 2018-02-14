#include "PSO.h"
#include <random>
#include "Utils.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <iostream>
#include "GUI.h"


PSO::PSO(int dimensions_num, int particle_num, int max_it, double max_velocity, std::vector<std::pair<double, double>>* dimensions_limits)
	: dimensions_num(dimensions_num),
	particle_num(particle_num),
	max_it(max_it),
	max_velocity(max_velocity),
	dimensions_limits(dimensions_limits)
{
	particles.resize(particle_num);
	for (auto&& particle : particles)
	{		

		static std::default_random_engine re;
		particle.state.reserve(dimensions_num);
		particle.best_known_state.reserve(dimensions_num);
		particle.v.reserve(dimensions_num);
		for (auto j = 0; j < dimensions_num; ++j)
		{
			std::uniform_real_distribution<double> unif(dimensions_limits->at(j).first, dimensions_limits->at(j).second);
			auto rand_val = unif(re);
			particle.state.push_back(rand_val);
			particle.best_known_state.push_back(rand_val);

			std::uniform_real_distribution<double> unif2(0, max_velocity);
			particle.v.push_back(unif2(re));
		}
	}
}

PSO::~PSO()
{
}


double PSO::eval(std::vector<double>* p)
{	
	//Rastrigin
	auto total = 10.0 * p->size();
	for (auto&& value : *p)
	{
		total += (
			(value * value)
			- (10 * cos(2 * M_PI *value)));
	}

	return total;
}

Particle* PSO::run()
{
	Particle* best_particle = nullptr;	
	auto best_particle_eval = std::numeric_limits<double>::max();

	static std::default_random_engine re;

	//Run PSO
	auto c1 = 1.0, c2 = 1.0;

	for (auto i = 0; i < max_it; ++i)
	{	
		
		for (auto&& particle : particles)
		{
			if (&particle == best_particle)
				continue;

			auto eval = this->eval(&particle.state);
			if (eval < best_particle_eval)
			{
				best_particle = &particle;
				best_particle_eval = eval;
				continue;
			}
			if (eval < this->eval(&particle.best_known_state))
			{
				particle.best_known_state = particle.state;
			}

			std::uniform_real_distribution<double> unif;
			//Update particle velocity
			particle.v = particle.v + c1 * unif(re) * (particle.best_known_state - particle.state) + c2 * unif(re) * (best_particle->state - particle.state);

			auto tmp_state = particle.v + particle.state;
			for (auto j = 0; j < dimensions_num; ++j)
			{
				if (tmp_state[j] < dimensions_limits->at(j).first)
					tmp_state[j] = dimensions_limits->at(j).first;
				else if(tmp_state[j] > dimensions_limits->at(j).second)
					tmp_state[j] = dimensions_limits->at(j).second;
			}
			//Update particle position
			particle.state = tmp_state;
		}

		mtx_drawable_particles.lock();
		drawable_particles = particles;
		mtx_drawable_particles.unlock();

		std::cout << "Best particle:\t\t " << best_particle->to_string() << "\t\t\tEval: " << best_particle_eval << "\n";
	}


	return best_particle;
}
