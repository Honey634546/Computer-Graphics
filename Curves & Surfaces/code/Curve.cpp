#include "Curve.h"


Curve::Curve()
{

}

Curve::Curve(int num)
{
	this->num = num;
}


Curve::~Curve()
{

}



void Curve::Paint(ArgParser* args)
{

	glPointSize(5.0);
	glBegin(GL_POINTS);

	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < vArr.size(); i++)
	{
		glVertex3f(vArr[i].x(), vArr[i].y(), vArr[i].z());
	}
	glEnd();


	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (int i = 0; i < vArr.size(); i++)
	{
		glVertex3f(vArr[i].x(), vArr[i].y(), vArr[i].z());
	}
	glEnd();
}

