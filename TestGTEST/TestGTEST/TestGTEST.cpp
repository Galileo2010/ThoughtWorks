// TestGTEST.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gtest\gtest.h>

Game g1;

void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-7, 7, -7, 7);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);
	
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	for (int i = 0; i < 15; ++i)
	{
		glVertex2i(i - 7, -7);
		glVertex2i(i - 7, 7);
		glVertex2i(-7, i - 7);
		glVertex2i(7, i - 7);
	}
	glEnd();
	g1.Show();
	//glutSolidSphere(1.0, 40, 50);
	//int i = 0, j = 0;
	//glRecti(i - 7, 7 - j, i - 6, 6 - j);
	glutSwapBuffers();
	if (g1.autoEvolution)
	{
		Sleep(100);
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
			return;
		}
		g1.UpdateCurrentStatus();
		glutPostRedisplay();
	}

	else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN)
	{
		g1.autoEvolution = true;
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
	glutInitWindowSize(700, 700);
	glutCreateWindow("生命游戏");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc(display);
	glutMainLoop();

    return 0;
}

