// work2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<Windows.h>
#include <stdio.h>
#include <assert.h>
using namespace std;

#include "arg_parser.h"
#include "glCanvas.h"
#include "spline_parser.h"

// ====================================================================
// ====================================================================

int main(int argc, char* argv[]) {

	// parse the command line arguments & input file
	ArgParser* args = new ArgParser(argc, argv);
	SplineParser* splines = new SplineParser(args->input_file);

	// launch curve editor!
	if (args->gui) {
		GLCanvas glcanvas;
		glcanvas.initialize(args, splines);
		// this never returns...
	}

	// output as required
	splines->SaveBezier(args);
	splines->SaveBSpline(args);
	splines->SaveTriangles(args);

	// cleanup
	delete args;
	delete splines;
	return 0;
}




