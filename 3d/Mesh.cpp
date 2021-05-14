#include "Mesh.h"

Mesh::Mesh(std::vector<Point3D> vertecles, Point3D* color, int width)
{
	this->width = width;
	this->color = *color;
	this->vertecles = vertecles;
}

Mesh::Mesh()
{
}

std::vector<Point3D> Mesh::GetVertecles()
{
	return this->vertecles;
}

void Mesh::AddVertecles(std::vector<Point3D> &vertecles, Point3D* color)
{
	this->color = *color;
	for (int i = 0; i < vertecles.size(); i++) {
		this->vertecles.push_back(vertecles[i]);
	}
}

void Mesh::AddVertecle(Point3D &point)
{
	this->vertecles.push_back(point);
}

void Mesh::Combine(Mesh &mesh)
{
	std::vector<Point3D> vertecles = mesh.GetVertecles();
	for (int i = 0; i < vertecles.size(); i++) {
		this->vertecles.push_back(vertecles[i]);
	}
}

Point3D Mesh::GetColor()
{
	return color;
}

int Mesh::GetWidth()
{
	return width;
}
