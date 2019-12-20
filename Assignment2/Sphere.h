#pragma once
#include "Object3D.h"
class Sphere :
	public Object3D
{
private:
	Vec3f center;
	float radius;

public:
	Sphere(Vec3f center, float radius, Material* m);
	~Sphere();
	virtual bool intersect(const Ray& r, Hit& h, float tmin);
};

