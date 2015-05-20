#include <Windows.h>
#include <gl/GL.h>
#include <gl/glut.h>

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);
}

void trianlge(void)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0, 0);
	glVertex2d(5.0, 5.0);
	glColor3f(0, 1.0, 0);
	glVertex2d(25.0, 5.0);
	glColor3f(0, 0, 1.0);
	glVertex2d(5.0, 25.0);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	trianlge();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	{
		gluOrtho2D(0, 30, 0, 30*(GLfloat)h / (GLfloat)w);
	}
	else
	{
		gluOrtho2D(0, 30*(GLfloat)w / (GLfloat)h, 0, 30);
	}
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Smooth Triangle");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}