#include "BezierCurve.h"
#define _USE_MATH_DEFINES
#include<math.h>



void BezierCurve::Paint(ArgParser* args)
{
	Curve::Paint(args);
	int curve_tessellation = args->curve_tessellation;
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 1.0f, 0.0f);
	Vec3f temp;
	for (double j = 0; j < vArr.size()-3; j+=3)
	{
		for (double i = 0; i <= curve_tessellation; i++)
		{
			double t = i / curve_tessellation;
			double a1 = pow(1 - t, 3);
			double a2 = pow(1 - t, 2) * 3 * t;
			double a3 = 3 * t * t * (1 - t);
			double a4 = t * t * t;
			double x = a1 * vArr[j].x() + a2 * vArr[j+1].x() + a3 * vArr[j+2].x() + a4 * vArr[j+3].x();
			double y = a1 * vArr[j].y() + a2 * vArr[j+1].y() + a3 * vArr[j+2].y() + a4 * vArr[j+3].y();
			temp.Set(x, y, 0.0);
			glVertex3f(temp.x(), temp.y(), temp.z());
		}
	}
	glEnd();


}


void BezierCurve::OutputBSpline(FILE* file)
{
	fprintf(file, "bspline\n");
	fprintf(file, "num_vertices 4\n");
	float Be[16] = { -1,3,-3,1,3,-6,3,0,-3,3,0,0,1,0,0,0 };
	float Bs[16] = { -1,3,-3,1,3,-6,0,4,-3,3,3,1,1,0,0,0 };
	for (int i = 0; i < 16; i++)
	{
		Bs[i] /= 6;
	}
	Matrix Bezier(Be);
	Matrix BSpline(Bs);
	float G1[16] = { vArr[0].x(),vArr[1].x(),vArr[2].x(),vArr[3].x(),vArr[0].y(),vArr[1].y(),vArr[2].y(),vArr[3].y(),0,0,0,0,0,0,0,0 };
	Matrix Geometry(G1);
	Matrix G2;
	if (BSpline.Inverse())
	{
		G2 = Geometry * Bezier * BSpline;
	}
	for (int i = 0; i < 4; i++)
	{
		fprintf(file, "%f %f 0\n", G2.Get(i, 0), G2.Get(i, 1));
	}
}


void BezierCurve::OutputBezier(FILE* file)
{
	fprintf(file, "bezier\n");
	fprintf(file, "num_vertices %d\n",num);
	for (int i = 0; i < num; i++)
	{
		fprintf(file, "%f %f %f\n",vArr[i].x(),vArr[i].y(),vArr[i].z());
	}
}

//curve_editor - input spline06_torus.txt - curve_tessellation 4 - revolution_tessellation 10 - output torus_low.obj
TriangleMesh* BezierCurve::OutputTriangles(ArgParser* arg)
{	
	int curve_tessellation = arg->curve_tessellation;
	int revolution_tessellation = arg->revolution_tessellation;
	int cnum = curve_tessellation * (num - 1)/3+1;
	TriangleNet* tri = new TriangleNet(revolution_tessellation+1, cnum-1);

	vector<Vec3f> arr;
	Vec3f temp;
	for (double j = 0; j < vArr.size() - 3; j += 3)
	{
		for (double i = 0; i <= curve_tessellation; i++)
		{
			double t = i / double(curve_tessellation);
			double a1 = pow(1 - t, 3);
			double a2 = pow(1 - t, 2) * 3 * t;
			double a3 = 3 * t * t * (1 - t);
			double a4 = t * t * t;
			double x = a1 * vArr[j].x() + a2 * vArr[j + 1].x() + a3 * vArr[j + 2].x() + a4 * vArr[j + 3].x();
			double y = a1 * vArr[j].y() + a2 * vArr[j + 1].y() + a3 * vArr[j + 2].y() + a4 * vArr[j + 3].y();
			temp.Set(x, y, 0.0);
			arr.push_back(temp);
		}
		arr.pop_back();
	}
	arr.push_back(temp);
	for (int i = 0; i < cnum; i++)
	{
		Vec3f t(arr[i].x(), arr[i].y(), arr[i].z());
		for (int j = 0; j <= revolution_tessellation+1; j++)
		{
			double angle = 360.0 / revolution_tessellation/180*M_PI;
			//float t1[16] = { t.x(),t.y(),t.z(),1,0,0,0,0,0,0,0,0,0,0,0,0 };
			//float t2[16] = { cos(angle),0,-sin(angle),0,0,1,0,0,sin(angle),0,cos(angle),0,0,0,0,1 };

			//Matrix temp1(t1);
			//Matrix temp2(t2);
			//Matrix temp3 = temp1 * temp2;
			double x = t.x() * cos(angle) + t.z() * sin(angle);
			double y = t.y();
			double z = t.x() * -1.0 * sin(angle) + t.z() * cos(angle);
			tri->SetVertex(j, i, t);
			//t.Set(temp3.Get(0,0),temp3.Get(1,0),temp3.Get(2,0));
			t.Set(x, y, z);
		}
	}
	return tri;
}

