#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <functional>
#include <cassert>
#include <vector>

template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b)
{
	assert(a.size() == b.size());

	std::vector<T> result;
	result.reserve(a.size());

	std::transform(a.begin(), a.end(), b.begin(),
		std::back_inserter(result), std::plus<T>());
	return result;
}


template <typename T>
std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b)
{
	assert(a.size() == b.size());

	std::vector<T> result;
	result.reserve(a.size());

	std::transform(a.begin(), a.end(), b.begin(),
		std::back_inserter(result), std::minus<T>());
	return result;
}

template <typename T>
std::vector<T> operator*(const double& a, const std::vector<T>& b)
{
	std::vector<T> result;
	result.reserve(b.size());

	for (auto i = 0; i < b.size(); ++i)
	{
		result.push_back(b[i] * a);
	}
	return result;
}

#endif