#pragma once
#include "Render.h"
class MonoBahivour
{
public:
	MonoBahivour(Render* render);
	/// <summary>
	/// ����������� ���� ��� � ������ ���������
	/// </summary>
	virtual void Start();
	/// <summary>
	/// ����������� �� ������ ����� ���������
	/// </summary>
	virtual void Update();
protected:
	Render* render;
};

