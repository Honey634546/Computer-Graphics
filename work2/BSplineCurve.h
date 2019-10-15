#pragma once
#include "Curve.h"
class BSplineCurve :
	public Curve
{
public:
	BSplineCurve(int& num) :Curve(num) {};
	void Paint(ArgParser* args);
	void OutputBSpline(FILE* file);
	void OutputBezier(FILE* file);
	void deleteControlPoint(int selectedPoint);
	void addControlPoint(int selectedPoint,float x, float y);
	TriangleMesh* OutputTriangles(ArgParser* arg);
};

