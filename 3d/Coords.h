#pragma once
#include "MonoBahivour.h"

/// <summary>
/// ����� ��� �������� ������� ���������
/// </summary>
class Coords :
    public MonoBahivour
{
public:
    Coords(Render* render) : MonoBahivour(render) {}
    virtual void Start()override;
private:
    /// <summary>
    /// ������ �������� ������� ���������
    /// </summary>
    double lenghCoords = 20;
};

