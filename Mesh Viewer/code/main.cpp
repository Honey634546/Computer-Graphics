// work1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<string>
#include <iostream>
#include<fstream>
#include<gl/glut.h>
#include<ctime>
#include<vector>
using namespace std;

float mousex, mousey;
float angleX, angleY;
float distanceX, distanceY;
bool color = true;
int direction = 0;
GLfloat position[4] = { 1.0, 1.0, 5.0, 0.0 };
vector<vector<float>> vArr;
vector<vector<float>> nArr;
bool spining = false;
bool spining2 = false;
bool leftDown;
bool rightDown;
GLfloat red=0.2, green=0.2, blue=0.2;
GLfloat old_red, old_green, old_blue;
GLfloat tar_red, tar_green, tar_blue;
GLfloat times = 1.0;
bool gradually = false;
int num = 0;
/*
 * Initialize depth buffer, projection matrix, light source, and lighting
 * model.  Do not specify a material property here.
 */
void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

	//光源位置
	GLfloat position[] = { 1.0, 1.0, 5.0, 0.0 };

	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glFrontFace(GL_CW);
	glEnable(GL_LIGHTING);



	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
}

void timerProc(int value)
{
	if (spining)
	{
		//glTranslatef(4, 8, 0.0);
		glRotatef(1.0, 0, 1.0, 0);
		//glTranslatef(-4, -8, 0.0);
		glutPostRedisplay();
		//glutTimerFunc(100, timerProc, 1);
	}

}

void glutcube(void)
{
	for (auto val : nArr)
	{
		glBegin(GL_TRIANGLES);
		glVertex3d(vArr[val[0] - 1][0], vArr[val[0] - 1][1], vArr[val[0] - 1][2]);
		glVertex3d(vArr[val[1] - 1][0], vArr[val[1] - 1][1], vArr[val[1] - 1][2]);
		glVertex3d(vArr[val[2] - 1][0], vArr[val[2] - 1][1], vArr[val[2] - 1][2]);
		glEnd();
	}
}

void mydisplay(void)
{
	//cout << "display" << endl;
	GLfloat mat[4];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPushMatrix();
	//glTranslatef(4, 8, 0.0);
	//glTranslatef(1, 1, 0.0);
	glTranslatef(distanceX, distanceY, 0);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	distanceX = distanceY = 0;
	angleX = angleY = 0;
	//glTranslatef(-8, -8, 0.0);
	//teapot的颜色
	if (color)
	{
		old_red = red;
		old_green = green;
		old_blue = blue;
		tar_red = (double)rand() / RAND_MAX;
		tar_green = (double)rand() / RAND_MAX;
		tar_blue = (double)rand() / RAND_MAX;
		//cout << old_red << " " << old_green << " " << old_blue << endl;
		//cout << tar_red << " " << tar_green << " " << tar_blue << endl;
		color = false;
		gradually = true;
	}
	//颜色渐变
	if (gradually)
	{
		float a = 0, b = 0, c = 0;
		a = abs(tar_red - old_red) / 100;
		b = abs(tar_green - old_green) / 100;
		c = abs(tar_blue - old_blue) / 100;
		if (tar_red - old_red > 0)
			red += a;
		else
			red -= a;
		if (tar_green - old_green > 0)
			green += b;
		else
			green -= b;
		if (tar_blue - old_blue > 0)
			blue += c;
		else
			blue -= c;
		if (num < 100)
		{
			num++;
			glutPostRedisplay();
		}
		else
		{
			gradually = false;
			num = 0;
		}

	}
	mat[0] = red;
	mat[1] = green;
	mat[2] = blue;
	if (spining)
	{
		if (spining2) {
			//cout << "spin" << endl;
			glutTimerFunc(100, timerProc, 1);
		}
		else
		{
			spining2 = true;
			timerProc(1);

		}

	}
	glScalef(times, times, times);
	times = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	//cout << direction << endl;
	switch (direction)
	{
	case 1:
		position[0] += 0.5; break;
	case 2:
		position[0] -= 0.5; break;
	case 3:
		position[1] += 0.5; break;
	case 4:
		position[1] -= 0.5; break;

	default:
		break;
	}
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	//glutSolidTeapot(3.0);
	glutcube();
	glPopMatrix();

	glFlush();

}



void display(void)
{
	//cout << "display" << endl;
	GLfloat mat[4];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPushMatrix();
	//glTranslatef(4, 8, 0.0);
	//glTranslatef(1, 1, 0.0);
	glTranslatef(distanceX, distanceY, 0);
	glRotatef(angleX, 1, 0, 0);
	glRotatef(angleY, 0, 1, 0);
	distanceX = distanceY = 0;
	angleX = angleY = 0;
	//glTranslatef(-8, -8, 0.0);
	//teapot的颜色
	if (color)
	{
		old_red = red;
		old_green = green;
		old_blue = blue;
		tar_red = (double)rand() / RAND_MAX;
		tar_green= (double)rand() / RAND_MAX;
		tar_blue = (double)rand() / RAND_MAX;
		//cout << old_red << " " << old_green << " " << old_blue << endl;
		//cout << tar_red << " " << tar_green << " " << tar_blue << endl;
		color = false;
		gradually = true;
	}
	//颜色渐变
	if (gradually)
	{
		float a=0, b=0, c=0;
		a = abs(tar_red - old_red) / 100;
		b = abs(tar_green - old_green) / 100;
		c = abs(tar_blue - old_blue) / 100;
		if (tar_red - old_red > 0)
			red += a;
		else
			red -= a;
		if (tar_green - old_green > 0)
			green += b;
		else 
			green -= b;
		if (tar_blue - old_blue > 0)
			blue += c;
		else
			blue -= c;
		if (num < 100)
		{
			num++;
			glutPostRedisplay();
		}
		else
		{
			gradually = false;
			num = 0;
		}

	}
	mat[0] = red;
	mat[1] = green;
	mat[2] = blue;
	if (spining)
	{
		if (spining2) {
			//cout << "spin" << endl;
			glutTimerFunc(100, timerProc, 1);
		}
		else
		{
			spining2 = true;
			timerProc(1);

		}

	} 
	glScalef(times, times, times);
	times = 1;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	//cout << direction << endl;
	switch (direction)
	{
	case 1:
		position[0] += 0.5; break;
	case 2:
		position[0] -= 0.5; break;
	case 3:
		position[1] += 0.5; break;
	case 4:
		position[1] -= 0.5; break;

	default:
		break;
	}
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glutSolidTeapot(3.0);
	//glutcube();
	glPopMatrix();

	glFlush();
}



void readobj(string filename)
{

	//string filename = "cube.obj";
	ifstream fin(filename);
	char ch;
	float a, b, c;
	while (!fin.eof())
	{
		fin >> ch >> a >> b >> c;
		if (ch == 'v')
		{
			vector<float> temp;
			temp.push_back(a);
			temp.push_back(b);
			temp.push_back(c);
			vArr.push_back(temp);
		}
		else if (ch == 'f')
		{
			vector<float> temp;
			temp.push_back(a);
			temp.push_back(b);
			temp.push_back(c);
			nArr.push_back(temp);
		}
		else
			continue;
	}
	//for (auto val : nArr)
	//	for (auto v : val)
	//		cout << v << " ";
	//cout << endl;
	//for (auto val : vArr)
	//	for (auto v : val)
	//		cout << v << " ";
	//cout << endl;
}


void reshape(int w, int h)
{
	//cout << "reshape" << endl;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(0.0, 16.0, 0.0, 16.0 * (GLfloat)h / (GLfloat)w,
			-10.0, 10.0);
	else
		glOrtho(0.0, 16.0 * (GLfloat)w / (GLfloat)h, 0.0, 16.0,
			-10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	//cout << "keyboard" << endl;
	//cout << key << " " << GLUT_KEY_DOWN;
	switch (key) {
	case 27:
		exit(0);
		break;
	case 'c':
		color =true; spining2 = false; break;
	case 'r':
		spining = !spining; spining2 = true; break;
	case 'b':
		times += 0.01; break;
	case 's':
		times -= 0.01;break;
	default:
		break;
	}
	cout << "Unhandled key press " << key << endl;
	glutPostRedisplay();
}

void specialkey(int key, int x, int y)
{
	//cout << "specialkey" << endl;
	switch (key) {
	case GLUT_KEY_UP:
		direction = 3; spining2 = false; break;
	case GLUT_KEY_DOWN:
		direction = 4; spining2 = false; break;
	case GLUT_KEY_LEFT:
		direction = 2; spining2 = false; break;
	case GLUT_KEY_RIGHT:
		direction = 1; spining2 = false; break;
	default:
		
		//cout << 'a';
		//cout << "Unhandled key press " << key << endl;
		break;
	}
	glutPostRedisplay();
}

void myMouse(int button, int state, int x, int y) {
	//cout << "mouse" << endl;
	mousex = x;
	mousey = y;
	if (state == GLUT_DOWN) {
		if (button == GLUT_LEFT_BUTTON) {
			leftDown = true;
		}
		else if (button == GLUT_RIGHT_BUTTON)
			rightDown = true;
	}
	else
	{
		if (button == GLUT_LEFT_BUTTON)
			leftDown = false;
		else if (button == GLUT_RIGHT_BUTTON)
			rightDown = false;
	}
	glutPostRedisplay();
	//return;
}

void myMouse2(int x, int y)
{
	distanceX = distanceY = 0;
	angleX = angleY = 0;
	if (leftDown)
	{
		angleX += (x - mousex) ;
		angleY += (x - mousex);
		mousex = x;
		mousey = y;
		//cout << angleX << " " << angleY << endl;
	}
	if (rightDown)
	{
		distanceX = (x - mousex) * 0.02;
		distanceY = -(y - mousey) * 0.02;
		mousex = x;
		mousey = y;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("hello world");
	init();
a:	cout << "teabot?(y/n)" << endl;
	char ch;
	cin >> ch;
	if(ch=='y' || ch=='Y')
		glutDisplayFunc(display);
	else if (ch == 'n' || ch == 'N')
	{
		string filename;
		cout << "please input filename" << endl;
		cin >> filename;
		readobj(filename);
		glutDisplayFunc(mydisplay);
	}
	else
	{
		goto a;
	}
	//readobj();
	glutReshapeFunc(reshape);
	glutTimerFunc(100, timerProc, 1);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkey);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMouse2);
	glutMainLoop();
	return 0;
}
