﻿// Assignment2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <cassert>
#include <assert.h>
#include"SceneParser.h"
#include "image.h"
#include "matrix.h"
#include "camera.h" 
#include "material.h"
#include "object3d.h"
#include "group.h" 
#include "sphere.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	char* input_file = NULL;
	int width = 100;
	int height = 100;
	char* output_file = NULL;
	float depth_min = 0;
	float depth_max = 1;
	char* depth_file = NULL;

	// sample command line:
	// raytracer -input scene1_1.txt -size 200 200 -output output1_1.tga -depth 9 10 depth1_1.tga

	for (int i = 1; i < argc; i++) 
	{
		if (!strcmp(argv[i], "-input")) 
		{
			i++; assert(i < argc);
			input_file = argv[i];
		}
		else if (!strcmp(argv[i], "-size")) 
		{
			i++; assert(i < argc);
			width = atoi(argv[i]);
			i++; assert(i < argc);
			height = atoi(argv[i]);
		}
		else if (!strcmp(argv[i], "-output")) 
		{
			i++; assert(i < argc);
			output_file = argv[i];
		}
		else if (!strcmp(argv[i], "-depth")) 
		{
			i++; assert(i < argc);
			depth_min = atof(argv[i]);
			i++; assert(i < argc);
			depth_max = atof(argv[i]);
			i++; assert(i < argc);
			depth_file = argv[i];
		}
		else 
		{
			printf("whoops error with command line argument %d: '%s'\n", i, argv[i]);
			assert(0);
		}
	}
	SceneParser sceneParser(input_file);

	Image image(width, height);
	Image depthImage(width, height);

	image.SetAllPixels(sceneParser.getBackgroundColor());
	depthImage.SetAllPixels(Vec3f(0, 0, 0));

	Group* pGroup = sceneParser.getGroup();
	Camera* pCamera = sceneParser.getCamera();

	for (float i = 0; i < width; i++)
	{
		for (float j = 0; j < height; j++)
		{
			Vec2f point((i / width), (j / height));
			Ray ray = pCamera->generateRay(point);
			Hit hit(INT_MAX,NULL);
			float tmin = pCamera->getTMin();
			if (pGroup->intersect(ray, hit, tmin))
			{
				image.SetPixel(i,j, hit.getMaterial()->getDiffuseColor());

				float depth = hit.getT();
				float c = (depth_max - depth) / (depth_max - depth_min);
				depthImage.SetPixel(i, j, Vec3f(c, c, c));
			}
		}
	}
	image.SaveTGA(output_file);
	depthImage.SaveTGA(depth_file);
	return 0;


}
