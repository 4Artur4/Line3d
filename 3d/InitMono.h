#pragma once
#include "Render.h"
#include "MonoBahivour.h"
#include <vector>
/// <summary>
/// ����� ��� ������������� ���� ����������� �������
/// </summary>
class InitMono
{
public:
	/// <summary>
	/// ������� ��� ����������� ������ � ����� ��������� Start
	/// </summary>
	/// <param name="render">����� ������� ��� ���������</param>
	InitMono(Render* render);
	/// <summary>
	/// �� ������ ����� �����������
	/// </summary>
	void Update();
private:
	void Init(Render* render);
	std::vector<MonoBahivour*> behaivours;
};

