#pragma once
#include"arg_parser.h"
#include"triangle_mesh.h"
#include"vectors.h"
#include<vector>
#include"matrix.h"
#include<gl/glut.h>
class Spline
{
public:
	//Vec3f vArr[4];
	vector<Vec3f> vArr;
	int num;
	virtual void set(int i, Vec3f v) {
		this->vArr.insert(vArr.begin() + i, v);
	};
	// 用于画图的FOR VISUALIZATION
	virtual void Paint(ArgParser* args) {};

	// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE* file) {};
	virtual void OutputBSpline(FILE* file) {};

	// 用于得到控制点的FOR CONTROL POINT PICKING	
	virtual int getNumVertices() {
		return num;
	};
	virtual Vec3f getVertex(int i)
	{
		return vArr.at(i);
	};

	// 用于编辑操作的FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y) {
		vArr[selectedPoint].Set(x, y, 0);
	};
	virtual void addControlPoint(int selectedPoint, float x, float y) {};
	virtual void deleteControlPoint(int selectedPoint) {};

	// 用于产生三角形的FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser* args) {
		return 0;
	};
};

