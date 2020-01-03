#pragma once
#include"ray.h"
#include"vectors.h"
class Camera
{
public:
	Camera();
	~Camera();
	virtual Ray generateRay(Vec2f point) = 0;
	virtual float getTMin() const = 0;
protected:
	Vec3f center;
	Vec3f direction;
	Vec3f up;
	Vec3f horizontal;
};

