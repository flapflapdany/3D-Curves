#pragma once
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
using namespace std;

class Point 
{
public:
	double x;
	double y;
	double z;
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	friend ostream& operator<<(ostream& os, const Point& thispoint);
};

ostream& operator<<(ostream& os, const Point& thispoint)
{
	os << "(" << thispoint.x << ", " << thispoint.y << ", " << thispoint.z << " )";
	return os;
}

class Vector
{
public:
	double x;
	double y;
	double z;
	Vector(double x, double y, double z) : x(x), y(y), z(z) {}
	friend ostream& operator<<(ostream& os, const Vector& thisvector);
};

ostream&operator<<(ostream& os, const Vector& thisvector)
{
	os << "[ " << thisvector.x << ", " << thisvector.y << ", " << thisvector.z <<" ]";
	return os;
}

class Curve
{
public:
	virtual Point GetPoint(double t) { return(Point(0, 0, 0)); }
	virtual Vector GetDerivative(double t) { return(Vector(0, 0, 0)); }
};

class Circle :public Curve
{
	double radius;
	Point  center;
public:
	Circle(double radius, Point center) :radius(radius), center(center) {}
	Point GetCenter() { return center; }
	double GetRadius() { return radius; }
	Point GetPoint(double t)
	{
		double x, y;
		x = center.x + radius * cos(t);
		y = center.y + radius * sin(t);
		return Point(x, y, 0);
	}
	Vector GetDerivative(double t)
	{
		double x, y;
		x = radius * (-sin(t));
		y = radius * cos(t);
		return Vector(x, y, 0);
	}
};

class Ellipse :public Curve
{
	double radius1;
	double radius2;
	Point center;
public:
	Ellipse(double radius1, double radius2, Point center) :radius1(radius1), radius2(radius2), center(center) {}
	Point GetPoint(double t)
	{
		double x, y;
		x = center.x + radius1 * cos(t);
		y = center.y + radius2 * sin(t);
		return Point(x, y, 0);
	}
	Vector GetDerivative(double t)
	{
		double x, y;
		x = radius1 *(-sin(t));
		y = radius2* cos(t);
		return Vector(x, y, 0);
	}
};

class Helix :public Curve
{
	double step;
	double radius;
	Point center;
public:
	Helix(double step, double radius, Point center):step(step), radius(radius), center(center){}
	Point GetPoint(double t)
	{
		double x, y, z;
		x = center.x + radius * cos(t);
		y = center.y + radius * sin(t);
		z = center.z+t * step / (M_PI * 2);
		return Point(x, y, z);
	}
	Vector GetDerivative(double t)
	{
		double x, y, z;
		x = radius * (-sin(t));
		y = radius * cos(t);
		z = step / (M_PI * 2);
		return Vector(x, y, z);
	}
};