// TestGTEST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gtest\gtest.h>

#define MaxX 30
#define MaxY 15

Game g1(MaxY * 2, MaxX * 2);

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-MaxX, MaxX, -MaxY, MaxY);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	
	g1.Show();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	for (int i = 0; i < MaxY; ++i)
	{
		glVertex2i(-MaxX, i);
		glVertex2i( MaxX, i);
		glVertex2i(-MaxX, -i);
		glVertex2i( MaxX, -i);
	}
	for (int i = 0; i < MaxX; ++i)
	{
		glVertex2i(-i, MaxY);
		glVertex2i(-i, -MaxY);
		glVertex2i(i, MaxY);
		glVertex2i(i, -MaxY);
	}
	glEnd();
	
	//glutSolidSphere(1.0, 40, 50);
	//int i = 0, j = 0;
	//glRecti(i - 7, 7 - j, i - 6, 6 - j);
	glutSwapBuffers();
	if (g1.autoEvolution)
	{
		Sleep(g1.sleepTime);
		g1.UpdateCurrentStatus();
	}
}
void mouse(int Button, int State, int x, int y)
{
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		if (g1.autoEvolution == true)
		{
			g1.autoEvolution = false;
			glutPostRedisplay();
		}
		else
		{
			g1.UpdateCurrentStatus();
			glutPostRedisplay();
		}
	}

	else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN)
	{
		g1.autoEvolution = true;
		glutPostRedisplay();
	}

	else if(Button == GLUT_MIDDLE_BUTTON && State == GLUT_DOWN)
	{
		g1.ReStart();
		glutPostRedisplay();
	}
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 'a' || key == 'A')
	{
		g1.sleepTime -= 100;
		if (g1.sleepTime <= 0)
			g1.sleepTime = 10;
		glutPostRedisplay();
	}
	else if (key == 'z' || key == 'Z')
	{
		if(g1.sleepTime < 2000)
			g1.sleepTime += 100;
		glutPostRedisplay();
	}
}

int main(int argc, char* argv[])
{
	//testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("生命游戏");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(processNormalKeys);
	glutIdleFunc(display);
	glutMainLoop();

    return 0;
}

