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
	// ���ڻ�ͼ��FOR VISUALIZATION
	virtual void Paint(ArgParser* args) {};

	// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE* file) {};
	virtual void OutputBSpline(FILE* file) {};

	// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING	
	virtual int getNumVertices() {
		return num;
	};
	virtual Vec3f getVertex(int i)
	{
		return vArr.at(i);
	};

	// ���ڱ༭������FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y) {
		vArr[selectedPoint].Set(x, y, 0);
	};
	virtual void addControlPoint(int selectedPoint, float x, float y) {};
	virtual void deleteControlPoint(int selectedPoint) {};

	// ���ڲ��������ε�FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser* args) {
		return 0;
	};
};

