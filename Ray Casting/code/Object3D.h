#pragma once
#include"material.h"
#include"ray.h"
#include"hit.h"

class Object3D
{
protected:
	Material* pMaterial;
public:
	Object3D() {};
	~Object3D() {};
	virtual bool intersect(const Ray& r, Hit& h, float tmin) = 0;
};

