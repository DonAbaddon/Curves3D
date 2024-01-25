#define _USE_MATH_DEFINES
#include <iostream>
#include <numeric>
#include <vector>
#include <random>
#include <cmath>
#include "Curve3D.h"

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> sizeDist(10, 100);
	std::uniform_int_distribution<> typeDist(0, 2);
	std::uniform_real_distribution<double> valueDist(DBL_EPSILON, 1000);
	std::default_random_engine re;
	std::cout << std::fixed;
	std::cout.precision(4);

	//2
	size_t containerSize = sizeDist(gen);
	std::vector<Curve3D*> curves(containerSize);

	for (size_t i = 0; i < containerSize; i++)
	{
		int type = typeDist(gen);

		if(type == 0)
		{
			Circle3D* circle = new Circle3D(valueDist(re));
			curves[i] = circle;
		}
		else if(type == 1)
		{
			Ellipse3D* ellipse = new Ellipse3D(valueDist(re), valueDist(re));
			curves[i] = ellipse;
		}
		else
		{
			Helix3D* helix = new Helix3D(valueDist(re), valueDist(re));
			curves[i] = helix;
		}
	}

	//3
	double t = M_PI / 4;

	for (size_t i = 0; i < containerSize; i++)
	{
		Point3D point = curves[i]->GetPoint(t);
		Point3D derivative = curves[i]->GetDerivative(t);
		std::cout << i << ".\tPoint: (" << point.x << ", " << point.y << ", " << point.z << ").\tDerivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")." << std::endl;
	}

	//4
	std::vector<Circle3D*> circles;
	for (size_t i = 0; i < containerSize; i++)
	{
		if (typeid(*curves[i]) == typeid(Circle3D))
		{
			circles.push_back(static_cast<Circle3D*>(curves[i]));
		}
	}

	//5
	int i = 0;
	std::sort(circles.begin(), circles.end(), [](Circle3D* c1, Circle3D* c2) { return c1->GetRadius() < c2->GetRadius(); });

	//6
	double summ = 0;
	for (size_t i = 0; i < circles.size(); i++)
	{
		summ += circles[i]->GetRadius();
	}
	std::cout << std::endl << "Summ of circle radiuses: " << summ << std::endl;

	for (size_t i = 0; i < containerSize; i++)
	{
		delete curves[i];
	}

	return 0;
}