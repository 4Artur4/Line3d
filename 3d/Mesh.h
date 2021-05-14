#pragma once
#include <vector>
#include "Point3D.h"
/// <summary>
/// ��� � ������� ����� (��� ���� ��� ����� ������)
/// </summary>
class Mesh{
public:
	/// <summary>
	/// ����� ��������� � �������
	/// </summary>
	/// <param name=""></param>
	Mesh(std::vector<Point3D>, Point3D* color = new Point3D(1, 1, 1), int width = 5);
	Mesh();
	/// <summary>
	/// ���������� ��� �����
	/// </summary>
	/// <returns></returns>
	std::vector<Point3D> GetVertecles();
	/// <summary>
	/// ��������� ����� �� �������
	/// </summary>
	/// <param name=""></param>
	void AddVertecles(std::vector<Point3D>&, Point3D* color = new Point3D(1, 1, 1));
	/// <summary>
	/// ��������� ���� �����
	/// </summary>
	/// <param name="point"></param>
	void AddVertecle(Point3D &point);
	/// <summary>
	/// ���������� ���� � ����
	/// </summary>
	/// <param name="mesh"></param>
	void Combine(Mesh& mesh);
	Point3D GetColor();
	int GetWidth();
private:
	std::vector<Point3D> vertecles;
	Point3D color;
	int width = 5;
};

