#include "SurfaceOfRevolution.h"

SurfaceOfRevolution::SurfaceOfRevolution()
{

}

SurfaceOfRevolution::SurfaceOfRevolution(Curve* c)
{
	this->c = c;
}



void SurfaceOfRevolution::Paint(ArgParser* args)
{
	this->c->Paint(args);
}

Vec3f SurfaceOfRevolution::getVertex(int i)
{
	return this->c->getVertex(i);
}

int SurfaceOfRevolution::getNumVertices()
{
	return this->c->getNumVertices();
}




TriangleMesh* SurfaceOfRevolution::OutputTriangles(ArgParser* arg)
{
	return this->c->OutputTriangles(arg);
}


void SurfaceOfRevolution::OutputBSpline(FILE* file)
{
	fprintf(file, "surface_of_revolution\n");
	this->c->OutputBSpline(file);
}

void SurfaceOfRevolution::deleteControlPoint(int selectedPoint)
{
	this->c->deleteControlPoint(selectedPoint);
}

void SurfaceOfRevolution::moveControlPoint(int selectedPoint, float x, float y) {
	this->c->moveControlPoint(selectedPoint, x, y);
};

void SurfaceOfRevolution::addControlPoint(int selectedPoint, float x, float y)
{
	this->c->addControlPoint(selectedPoint, x, y);
}