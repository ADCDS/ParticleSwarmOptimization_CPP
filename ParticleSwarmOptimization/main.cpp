#include "PSO.h"
#include "GUI.h"
#include <thread>

int main()
{
	std::vector<std::pair<double, double>> dl = {
		{-5.12,5.12},{-5.12,5.12},
		{-5.12,5.12},{-5.12,5.12},
		{-5.12,5.12},{-5.12,5.12},
		{-5.12,5.12},{-5.12,5.12},
		{-5.12,5.12},{-5.12,5.12},
	};
	PSO pso(10, 10000, INT_MAX, 1, &dl);
	std::thread([&pso]()
	{
		GUI g;
		g.display(&pso);
	}).detach();
	pso.run();

	return 0;
}
