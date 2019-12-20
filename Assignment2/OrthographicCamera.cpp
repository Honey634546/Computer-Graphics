#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(Vec3f center, Vec3f direction, Vec3f up, float size) {
	this->center = center;
	this->direction = direction;
	this->up = up;
	this->size = size;
	Vec3f::Cross3(this->horizontal, this->direction, this->up);
	Vec3f::Cross3(this->up, this->horizontal, this->direction);
	this->direction.Normalize();
	this->up.Normalize();
	this->horizontal.Normalize();
}

Ray OrthographicCamera::generateRay(Vec2f point) {
	Vec3f origin = center + (point.x() - 0.5) * size * horizontal + (point.y() - 0.5) * size * up;
	return Ray(origin, direction);
}

float OrthographicCamera::getTMin() const{
	return (float)-INT_MAX;
}