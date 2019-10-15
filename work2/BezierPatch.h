#pragma once
#include "Surface.h"
class BezierPatch :
	public Surface
{
public:

	BezierPatch();
	void set(int i, Vec3f c);
	void Paint(ArgParser* args);
	TriangleMesh* OutputTriangles(ArgParser* args);
	Vec3f Suv(float u, float v);
};

