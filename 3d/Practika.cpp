#include "Practika.h"
using namespace std;

double Nurbs(int i, int n, vector<double> knots, double steps);

Point3D ResultNurbs(vector<Point3D> point, vector<double> weight, vector<double> knots, int n, double steps);

void Practika::Start()
{
	vector<Point3D> point;

	Point3D CardPoint0(0., 0., 0.);
	point.push_back(CardPoint0);

	Point3D CardPoint1(1., 1., 0.);
	point.push_back(CardPoint1);

	Point3D CardPoint2(2., -1., 0.);
	point.push_back(CardPoint2);

	Point3D CardPoint3(3., 1., 0.);
	point.push_back(CardPoint3);

	Point3D CardPoint4(4., -1., 0.);
	point.push_back(CardPoint4);

	Point3D CardPoint5(5., 1., 0.);
	point.push_back(CardPoint5);

	Point3D CardPoint6(6., -1., 0.);
	point.push_back(CardPoint6);

	Point3D CardPoint7(7., 1., 0.);
	point.push_back(CardPoint7);

	Point3D CardPoint8(8., -1., 0.);
	point.push_back(CardPoint8);

	Point3D CardPoint9(9., 1., 0.);
	point.push_back(CardPoint9);

	Point3D CardPoint10(10., -1., 0.);
	point.push_back(CardPoint10);

	Point3D CardPoint11(11., 1., 0.);
	point.push_back(CardPoint11);

	Point3D CardPoint12(12., -1., 0.);
	point.push_back(CardPoint12);

	Point3D CardPoint13(13., 1., 0.);
	point.push_back(CardPoint13);

	Point3D CardPoint14(14., -1., 0.);
	point.push_back(CardPoint14);
	//¬от тут создаетс€ меш из точек и сразу вывожитс€
	render->CreateMesh(&point);

	vector<double> weight = { 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1., 1. };
	vector<double> knots = { 0., 0., 0., 0., 0., 0., 0., 0., 0., 1., 1., 1., 1., 1., 1., 1., 1., 1. };


	for (int U = 0; U < 10; U += 1)
	{
		double steps = U * 0.1;
		Point3D result = ResultNurbs(point, weight, knots, 3, steps);
		//cout << result.x << "\t" << result.y << "\t" << result.z << endl;
	}

}


Point3D ResultNurbs(vector<Point3D> point, vector<double> weight, vector<double> knots, int n, double steps)
{
	double sum = 0;
	for (int i = 0; i < point.size(); i++)
	{
		sum += Nurbs(i, n, knots, steps) * weight.at(i);
	}
	if (sum == 0.0)
	{
		Point3D r;
		return r;
	}

	double numX = 0., numY = 0., numZ = 0.;
	for (int i = 0; i < point.size(); i++)
	{
		numX += Nurbs(i, n, knots, steps) * weight.at(i) * point.at(i).x;
		numY += Nurbs(i, n, knots, steps) * weight.at(i) * point.at(i).y;
		numZ += Nurbs(i, n, knots, steps) * weight.at(i) * point.at(i).z;
	}

	Point3D result(numX / sum, numY / sum, numZ / sum);
	return result;
}


double Nurbs(int i, int n, vector<double> knots, double steps)
{
	if (n == 1)
	{
		if (i < knots.size() - 1)
		{
			if ((steps >= knots.at(i)) && (steps < knots.at(i + 1)))
				return 1;
			else
				return 0;
		}
		else if ((i == knots.size() - 1) && (steps == knots.at(i)))
			return 1;
		return 0;
	}
	else
	{
		double C;
		double A = (steps - knots.at(i));
		double A1 = (knots.at(i + n) - knots.at(i));
		if (A1 == 0)
			C = 0;
		else
			C = A / A1;

		double D;
		double B = (knots.at(i + n) - steps);
		double B1 = (knots.at(i + n) - knots.at(i + 1));
		if (B1 == 0)
			D = 0;
		else
			D = B / B1;

		double N;
		N = C * Nurbs(i, n - 1, knots, steps) + D * Nurbs(i + 1, n - 1, knots, steps);

		return N;
	}
}