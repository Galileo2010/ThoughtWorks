// TestGTEST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gtest\gtest.h>
#include <thread>

#define MaxX 60
#define MaxY 30
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
	glutSwapBuffers();

	if (g1.GetAutoEvolution())
	{
		Sleep(g1.GetsleepTime());
		g1.UpdateCurrentStatus();
	}
}
void mouse(int Button, int State, int x, int y)
{
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		if (g1.GetAutoEvolution() == true)
		{
			g1.SetAutoEvolution (false);
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
		g1.SetAutoEvolution(true);
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
		int sleepTime = g1.GetsleepTime();
		sleepTime -= 100;
		g1.SetsleepTime(sleepTime);
		if (g1.GetsleepTime() <= 0)
			g1.SetsleepTime(1);
		glutPostRedisplay();
	}
	else if (key == 'z' || key == 'Z')
	{
		int sleepTime = g1.GetsleepTime();
		sleepTime += 100;
		if(g1.GetsleepTime() < 2000)
			g1.SetsleepTime(sleepTime);
		glutPostRedisplay();
	}
}

int main(int argc, char* argv[])
{
	// 单元测试，开启多线程
	testing::InitGoogleTest(&argc, argv);
	thread td(RUN_ALL_TESTS);
	td.detach();

	// 界面
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

