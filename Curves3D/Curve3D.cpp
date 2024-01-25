#define _USE_MATH_DEFINES
#include <cmath>
#include "Curve3D.h"

Point3D Curve3D::GetPoint(double t)
{
	throw "No points for this curve";;
}

Point3D Curve3D::GetDerivative(double t)
{
	throw "No derivatives for this curve";
}

Circle3D::Circle3D(double radius)
{
	if (radius <= 0) throw "Radius must be positive";
	this->radius = radius;
}

Point3D Circle3D::GetPoint(double t)
{
	return Point3D(radius * cos(t), radius * sin(t), 0);
}

Point3D Circle3D::GetDerivative(double t)
{
	return Point3D(-radius * sin(t), radius * cos(t), 0);
}

double Circle3D::GetRadius()
{
	return radius;
}

Ellipse3D::Ellipse3D(double xRadius, double yRadius)
{
	if (xRadius <= 0 || yRadius <= 0) throw "Radius must be positive";
	this->xRadius = xRadius;
	this->yRadius = yRadius;
}

Point3D Ellipse3D::GetPoint(double t)
{
	return Point3D(xRadius * cos(t), yRadius * sin(t), 0);
}

Point3D Ellipse3D::GetDerivative(double t)
{
	return Point3D(-xRadius * sin(t), yRadius * cos(t), 0);
}

Helix3D::Helix3D(double radius, double step)
{
	if (radius <= 0 || step <= 0) throw "Radius and step must be positive";
	this->radius = radius;
	this->step = step;
}

Point3D Helix3D::GetPoint(double t)
{
	return Point3D(radius * cos(t), radius * sin(t), step * t / (2 * M_PI));
}

Point3D Helix3D::GetDerivative(double t)
{
	return Point3D(radius * cos(t), radius * sin(t), step / (2 * M_PI));
}
