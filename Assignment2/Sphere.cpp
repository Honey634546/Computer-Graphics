#include "Sphere.h"

Sphere::Sphere(Vec3f center, float radius, Material* m)
{
	this->center = center;
	this->radius = radius;
	this->pMaterial = m;
}

Sphere::~Sphere()
{

}

bool Sphere::intersect(const Ray& r, Hit& h, float tmin)
{
	//TODO
	Vec3f origin = r.getOrigin();
	Vec3f direction = r.getDirection();
	float A = direction.Dot3(direction);
	float B = 2 * direction.Dot3(origin - center);
	float C = (origin - this->center).Dot3(origin - center) - radius * radius;
	float deta = B * B - 4 * A * C;
	if (deta < 0)
	{
		return false;
	}
	else
	{
		float t1 = (-B + sqrt(deta)) / (2 * A);
		float t2 = (-B - sqrt(deta)) / (2 * A);
		float t = 0;
		if (t2 >= tmin)
		{
			t = t2;
		}
		else if (t1 >= tmin)
		{
			t = t1;
		}
		else
		{
			return false;
		}
		if (t < h.getT())
		{
			h.set(t, pMaterial, r);
			return true;
		}
	}
	return false;
		
}
