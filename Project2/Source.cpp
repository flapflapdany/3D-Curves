#define _USE_MATH_DEFINES 
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <typeinfo>
#include <algorithm>
#include "Header.h"
using namespace std;

void PrintTable(Curve* Curve1, double t)
{
	cout << "  " << typeid(*Curve1).name() << "  " << Curve1->GetPoint(t) << "  " << Curve1->GetDerivative(t) << endl;
	cout << "___________________________________________________________________" << endl;
}

bool comp(Circle* circle1, Circle* circle2) { return circle1->GetRadius() < circle2->GetRadius(); }

void main()
{
	srand(time(NULL));
	vector<Curve*> curve1;
	vector<Circle*> circles;
	int count = rand() % 20 + 1;
	int choiñe_curve;
	double rand_radius;
	for (int i = 0; i < count; i++)
	{
		choiñe_curve = rand() % 3;
		rand_radius = (double)((rand() % 500 + 1)/10.0);
		double x = (double)((rand() % 1000 - 1000) / 10.0);//-100-100
		double y = (double)((rand() % 1000 - 1000) / 10.0);
		double z = (double)((rand() % 1000 - 1000) / 10.0);
		Point centre(x, y, z);
		switch (choiñe_curve)
		{
		case(0):
		{
			curve1.push_back(new Circle(rand_radius, centre));
			break;
		}
		case(1):
		{
			double rand_radius2 = (double)((rand() % 500 + 1) / 10.0);
			curve1.push_back(new Ellipse(rand_radius, rand_radius2, centre));
			break;
		}
		case(2):
		{
			double step = (double)((rand() % 20 + 1) / 10.0);
			curve1.push_back(new Helix(rand_radius, step, centre));
			break;
		}
		};
	}
	int j = 0;
	double t = M_PI / 4;
	cout << "     Curve                  Point               First derivative   " << endl;
	cout << "___________________________________________________________________" << endl;
	while (j != curve1.size())
	{
		PrintTable(curve1[j], t);
		if (typeid(*curve1[j]) == typeid(Circle))
		{
			circles.push_back(dynamic_cast<Circle*>(curve1[j]));
		}
		j++;
	}
	sort(circles.begin(), circles.end(), comp);
	double sum=0.0;
	for (auto circle : circles)
	{
		sum += circle->GetRadius();
		cout << circle->GetRadius() << endl;
	}
	//cout << sum;
}