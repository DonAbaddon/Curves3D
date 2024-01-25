#pragma once
#include "Point3D.h"

class Curve3D
{
public:
	virtual Point3D GetPoint(double t);
	virtual Point3D GetDerivative(double t);
};

class Circle3D : public Curve3D
{
public:
	Circle3D(double radius);
	Point3D GetPoint(double t) override;
	Point3D GetDerivative(double t) override;
	double GetRadius();
private:
	double radius;
};

class Ellipse3D : public Curve3D
{
public:
	Ellipse3D(double xRadius, double yRadius);
	Point3D GetPoint(double t) override;
	Point3D GetDerivative(double t) override;
private:
	double xRadius, yRadius;
};

class Helix3D : public Curve3D
{
public:
	Helix3D(double radius, double step);
	Point3D GetPoint(double t) override;
	Point3D GetDerivative(double t) override;
private:
	double radius, step;
};