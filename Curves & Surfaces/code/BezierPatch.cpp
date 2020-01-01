#include "BezierPatch.h"

BezierPatch::BezierPatch()
{
	num = 16;
}

void BezierPatch::set(int i, Vec3f c)
{
	this->vArr.insert(vArr.begin() + i, c);
}

//BezierPatch::BezierPatch(Curve* c):Surface(c)
//{
//}

void BezierPatch::Paint(ArgParser* args)
{
	glPointSize(5.0);
	glBegin(GL_POINTS);

	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < vArr.size(); i++)
	{
		glVertex3f(vArr[i].x(), vArr[i].y(), vArr[i].z());
	}
	glEnd();


	for (int i = 0; i < 4; i++)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 1.0f, 0.0f);
		for (double j = 0; j < 4; j++)
		{
			glVertex3f(vArr[i*4+j].x(), vArr[i * 4 + j].y(), vArr[i * 4 + j].z());
		}
		glEnd();
	}

}

//-input spline08_bezier_patch.txt - patch_tessellation 4 - output patch_low.obj
TriangleMesh* BezierPatch::OutputTriangles(ArgParser* args)
{
	int patch_tessellation = args->patch_tessellation;
	//int cnum=patch_tessellation* patch_tessellation + 1;
	TriangleNet* tri = new TriangleNet(patch_tessellation, patch_tessellation);
	float u, v;
	for (float i = 0; i <= patch_tessellation; i++)
	{
		u = i / (float)patch_tessellation;
		for (float j = 0; j<= patch_tessellation; j++)
		{
			v = j / (float)patch_tessellation;
			tri->SetVertex(j, i, Suv(u, v));
		}
	}
	return tri;
}

Vec3f BezierPatch::Suv(float u, float v)
{
	Vec3f temp;
	Matrix P[3];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			P[0].Set(j, i, vArr[4 * i + j].x());
			P[1].Set(j, i, vArr[4 * i + j].y());
			P[2].Set(j, i, vArr[4 * i + j].z());
		}
	}
	float uu[16], vv[16];
	for (int i = 0; i < 16; i++)
	{
		uu[i] = 1;
		vv[i] = 0;
	}
	uu[0] = u * u * u; uu[1] = u * u; uu[2] = u; uu[3] = 1;
	vv[0] = v * v * v; vv[4] = v * v; vv[8] = v; vv[12] = 1;
	Matrix U(uu);
	Matrix V(vv);
	float bz[16] = { -1,3,-3,1,3,-6,3,0,-3,3,0,0,1,0,0,0 };
	Matrix Bz(bz);
	Matrix X = U * Bz * P[0] * Bz * V;
	Matrix Y = U * Bz * P[1] * Bz * V;
	Matrix Z = U * Bz * P[2] * Bz * V;
	float x = X.Get(0, 0);
	float y = Y.Get(0, 0);
	float z = Z.Get(0, 0);
	temp.Set(x, y, z);
	return temp;
}