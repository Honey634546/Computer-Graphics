#pragma once
#include "Curve.h"

class BezierCurve :
	public Curve
{
public:
	BezierCurve(int& num) :Curve(num) {};
	void OutputBSpline(FILE* file);
	void OutputBezier(FILE* file);
	void Paint(ArgParser* args);
	TriangleMesh* OutputTriangles(ArgParser* arg);
};

