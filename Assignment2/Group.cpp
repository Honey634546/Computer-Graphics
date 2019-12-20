#include "Group.h"

Group::Group(int num)
{
	this->num = num;
	this->pObjs = new Object3D * [num];
}

Group::~Group()
{
	delete[] this->pObjs;
}

void Group::addObject(int index, Object3D* obj)
{
	this->pObjs[index] = obj;
}

bool Group::intersect(const Ray& r, Hit& h, float tmin)
{
	bool flag = false;
	for (int i = 0; i < num; i++)
	{
		if (pObjs[i]->intersect(r, h, tmin))
		{
			flag = true;
		}
	}
	return flag;
}