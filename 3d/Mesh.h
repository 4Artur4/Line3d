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
	Mesh(std::vector<Point3D>);
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
	void AddVertecles(std::vector<Point3D>&);
	/// <summary>
	/// ��������� ���� �����
	/// </summary>
	/// <param name="point"></param>
	void AddVertecle(Point3D &point);
	/// <summary>
	/// ���������� ���� � ����
	/// </summary>
	/// <param name="mesh"></param>
	void Combine(Mesh &mesh);
private:
	std::vector<Point3D> vertecles;
};

