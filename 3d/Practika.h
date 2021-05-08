#pragma once
#include "MonoBahivour.h"
class Practika :
    public MonoBahivour
{
public:
    Practika(Render* render) : MonoBahivour(render){}
    virtual void Start()override;
};

