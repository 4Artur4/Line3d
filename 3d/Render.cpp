#include "Render.h"

void Render::Update()
{
	this->Update(0, 0, 0);
}

void Render::Update(double rx, double ry, double rz)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(cameraPoint->x, cameraPoint->y, cameraPoint->z);	// Сдвинуть вглубь экрана

	glRotatef(rx, 1.0f, 0.0f, 0.0f);	// Вращение куба по X, Y, Z
	glRotatef(ry, 0.0f, 1.0f, 0.0f);	// Вращение куба по X, Y, Z
	glRotatef(rz, 0.0f, 0.0f, 1.0f);	// Вращение куба по X, Y, Z

	for (int i = 0; i < this->meshes.size(); i++) {
		this->PaintMesh(this->meshes[i]);
	}
}

Mesh* Render::CreateMesh()
{
	Mesh* mesh = new Mesh();
	this->meshes.push_back(*mesh);
	return mesh;
}

Mesh* Render::CreateMesh(std::vector<Point3D> *vertecles, Point3D* color)
{
	Mesh* mesh = new Mesh(*vertecles, color);
	this->meshes.push_back(*mesh);
	return mesh;
}

void Render::AddMesh(Mesh& mesh)
{
	this->meshes.push_back(mesh);
}

void Render::SetCameraPosition(Point3D* point)
{
	cameraPoint = point;
}

void Render::SetCameraPosition(double x, double y, double z)
{
	SetCameraPosition(new Point3D(x, y, z));
}

void Render::PaintMesh(Mesh mesh)
{

	glLineWidth(this->widthLine);
	glBegin(GL_LINES);
	glColor3d(mesh.GetColor().x, mesh.GetColor().y, mesh.GetColor().z);
	int countVertex = 0;
	for (int i = 0; i < mesh.GetVertecles().size();) {
		if (countVertex == 2) {
			countVertex = 0;
			i--;
		}
		glVertex3d(mesh.GetVertecles()[i].x,
			mesh.GetVertecles()[i].y,
			mesh.GetVertecles()[i].z);
		countVertex++;
		i++;
	}
	glEnd();
}
