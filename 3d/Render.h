#pragma once
#include "glut/glut.h"
#include "Mesh.h"
#include <vector>
class Render{
public:
	/// <summary>
	/// Каждый кадр отрисовывает все меши
	/// </summary>
	void Update();
	/// <summary>
	/// Каждый кадр отрисовывает все меши с поворотом на нужный угол
	/// </summary>
	/// <param name="rx"></param>
	/// <param name="ry"></param>
	/// <param name="rz"></param>
	void Update(double rx, double ry,double rz);
	/// <summary>
	/// Создает пустой мешь и сразу добавляет в массив отрисовки
	/// </summary>
	/// <returns></returns>
	Mesh* CreateMesh();
	/// <summary>
	/// Создает меш с набором точек и добавляет в массив отрисовки
	/// </summary>
	/// <param name="vertecles"></param>
	/// <returns></returns>
	Mesh* CreateMesh(std::vector<Point3D> *vertecles, Point3D* color = new Point3D(1, 1, 1));
	/// <summary>
	/// Добавляет меш в массив отриосовки
	/// </summary>
	/// <param name="mesh"></param>
	void AddMesh(Mesh &mesh);
	/// <summary>
	/// Устанавлвает позицию камеры
	/// </summary>
	/// <param name="point"></param>
	void SetCameraPosition(Point3D* point);
	/// <summary>
	/// Устанавлвает позицию камеры
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	void SetCameraPosition(double x, double y, double z);
private:
	std::vector<Mesh> meshes;
	int widthLine = 5;
	void PaintMesh(Mesh mesh);
	Point3D* cameraPoint = new Point3D(0,0,-50);
};

