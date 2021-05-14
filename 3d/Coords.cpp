#include "Coords.h"

void Coords::Start()
{
	render->CreateMesh(new std::vector<Point3D>{
		Point3D(0,0,0), Point3D(0,lenghCoords+0.1,0),
		Point3D(1,lenghCoords-1,0),Point3D(0,lenghCoords+0.1,0),
		Point3D(-1,lenghCoords-1,0)
		},new Point3D(0,1,0), 2);
	render->CreateMesh(new std::vector<Point3D>{
		Point3D(0,0,0), Point3D(lenghCoords+0.1,0,0),
		Point3D(lenghCoords -1,1,0),Point3D(lenghCoords + 0.1,0,0),
		Point3D(lenghCoords -1,-1,0)
		}, new Point3D(1, 0, 0),2);
	render->CreateMesh(new std::vector<Point3D>{
		Point3D(0,0,0), Point3D(0,0,lenghCoords+0.1),
		Point3D(0,1,lenghCoords -1),Point3D(0,0,lenghCoords + 0.1),
		Point3D(0,-1,lenghCoords -1)
		}, new Point3D(0, 0, 1),2);
}
