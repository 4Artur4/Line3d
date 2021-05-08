#pragma once
#include "Render.h"
class MonoBahivour
{
public:
	MonoBahivour(Render* render);
	/// <summary>
	/// Выполняется один раз в начале программы
	/// </summary>
	virtual void Start();
	/// <summary>
	/// Выполняется на каждом кадре программы
	/// </summary>
	virtual void Update();
protected:
	Render* render;
};

