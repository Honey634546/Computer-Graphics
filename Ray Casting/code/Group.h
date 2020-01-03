#pragma once
#include "Object3D.h"
class Group :
	public Object3D
{
private:
	Object3D** pObjs;
	int num;
public:
	Group(int num);
	~Group();
	void addObject(int index, Object3D* obj);
	virtual bool intersect(const Ray& r, Hit& h, float tmin);
};

