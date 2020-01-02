#include "ifs.h"
#include <stdio.h>
#include<cmath>

IFS::IFS()
{
	this->n = 0;
	this->transformation.clear();
	this->probability.clear();
}

IFS::~IFS() {

}

void IFS::readFile(char* filename)
{
	FILE* file;
	fopen_s(&file,filename, "r");
	//FILE* file = fopen(filename, "r");
	assert(file != NULL);
	n = this->readFloat(file);
	for (int i = 0; i < n; i++)
	{
		float p = this->readFloat(file);
		Matrix m;
		m.Read3x3(file);

		this->probability.push_back(p);
		this->transformation.push_back(m);
	}
	fclose(file);

}

void IFS::render(Image& image,float num_points, float num_iters)
{
	Vec3f color(0, 0, 0);
	int width = image.Width();
	int height = image.Height();

	for (int i = 0; i < num_points; ++i)
	{
		Vec2f v = Vec2f(rand() * 1.0f / RAND_MAX, rand() * 1.0f / RAND_MAX);
		for (int j = 0; j < num_iters; j++)
		{
			int k=0;
			float sum = 0;
			float t = rand() * 1.0f / RAND_MAX;
			for (k = 0; k < n; k++)
			{
				sum += this->probability[k];
				if (sum >= t)
					break;
				else if (k == n-1)
					break;
			}
			this->transformation[k].Transform(v);
		}
		if (v.x() >= 0 && v.x() <= 1 && v.y() >= 0 && v.y() <= 1) 
		{
			image.SetPixel((int)(v.x() * width), (int)(v.y() * height),color );
		}
	}

}

float IFS::readFloat(FILE* file)
{
	float answer;
	int count = fscanf_s(file, "%f", &answer);
	if (count != 1) {
		printf("Error trying to read 1 float\n");
		assert(0);
	}
	return answer;
}
