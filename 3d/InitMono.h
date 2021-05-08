#pragma once
#include "Render.h"
#include "MonoBahivour.h"
#include <vector>
/// <summary>
///  ласс дл€ инициализации всех исполн€ющих классов
/// </summary>
class InitMono
{
public:
	/// <summary>
	/// —оздает все исполн€ющие классы и сразу выполн€ет Start
	/// </summary>
	/// <param name="render"> ласс рендера дл€ отрисовки</param>
	InitMono(Render* render);
	/// <summary>
	/// Ќа каждом кадре выполн€етс€
	/// </summary>
	void Update();
private:
	void Init(Render* render);
	std::vector<MonoBahivour*> behaivours;
};

