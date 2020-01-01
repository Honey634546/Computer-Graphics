#pragma once
#include "Spline.h"
class Curve :
	public Spline
{
public:
	Curve();
	Curve(int num);
	~Curve();
	void Paint(ArgParser* args);
};

