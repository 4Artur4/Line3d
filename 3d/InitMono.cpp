#include "InitMono.h"
#include "Practika.h"
#include "Coords.h"

InitMono::InitMono(Render* render)
{
	this->Init(render);
}

void InitMono::Update()
{
	for (int i = 0; i < behaivours.size(); i++) {
		behaivours[i]->Update();
	}
}

void InitMono::Init(Render* render)
{
	//���� ����� �������� �������� ���� ������� MonoBehaivoir
	behaivours.push_back(new Practika(render));
	behaivours.push_back(new Coords(render));
	for (int i = 0; i < behaivours.size(); i++) {
		behaivours[i]->Start();
	}
}
