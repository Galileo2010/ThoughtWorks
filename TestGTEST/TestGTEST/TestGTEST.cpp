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
	//int i = 0, j = 0;
	//glRecti(i - 7, 7 - j, i - 6, 6 - j);
	glutSwapBuffers();
}
void mouse(int Button, int State, int x, int y)
{
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
			glutPostRedisplay();
	}
}

int main(int argc, char* argv[])
{
	//testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
	g1.cellStatus[0][1] = 1;
	g1.cellStatus[0][2] = 1;
	g1.cellStatus[1][0] = 1;

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

