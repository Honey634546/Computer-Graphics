#pragma once
#include "Surface.h"
class SurfaceOfRevolution :
	public Surface
{
public:
	SurfaceOfRevolution();
	SurfaceOfRevolution(Curve *c);
	virtual void Paint(ArgParser* args);
	virtual TriangleMesh* OutputTriangles(ArgParser* args);
	virtual int getNumVertices();
	virtual Vec3f getVertex(int i);
	virtual void OutputBSpline(FILE* file);
	virtual void deleteControlPoint(int selectedPoint);
	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
private:
	Curve* c;
};

