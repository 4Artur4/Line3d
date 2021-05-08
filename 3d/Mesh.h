#pragma once
#include <vector>
#include "Point3D.h"
/// <summary>
/// Меш с набором точек (щас пока как линия только)
/// </summary>
class Mesh{
public:
	/// <summary>
	/// Сразу создается с точками
	/// </summary>
	/// <param name=""></param>
	Mesh(std::vector<Point3D>);
	Mesh();
	/// <summary>
	/// возвращает все точки
	/// </summary>
	/// <returns></returns>
	std::vector<Point3D> GetVertecles();
	/// <summary>
	/// Добавляет точки из вектора
	/// </summary>
	/// <param name=""></param>
	void AddVertecles(std::vector<Point3D>&);
	/// <summary>
	/// Добавляет одну точку
	/// </summary>
	/// <param name="point"></param>
	void AddVertecle(Point3D &point);
	/// <summary>
	/// Соединятет меши в один
	/// </summary>
	/// <param name="mesh"></param>
	void Combine(Mesh &mesh);
private:
	std::vector<Point3D> vertecles;
};

