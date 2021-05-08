#include "InitMono.h"
#include "Practika.h"

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
	//—юда нужно встваить создание всех классов MonoBehaivoir
	behaivours.push_back(new Practika(render));
	for (int i = 0; i < behaivours.size(); i++) {
		behaivours[i]->Start();
	}
}
