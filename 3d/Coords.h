#pragma once
#include "MonoBahivour.h"

/// <summary>
/// Класс для создания системы координат
/// </summary>
class Coords :
    public MonoBahivour
{
public:
    Coords(Render* render) : MonoBahivour(render) {}
    virtual void Start()override;
private:
    /// <summary>
    /// Длянна отрезков системы координат
    /// </summary>
    double lenghCoords = 20;
};

