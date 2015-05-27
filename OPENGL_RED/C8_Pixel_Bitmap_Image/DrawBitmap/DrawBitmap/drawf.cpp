/*
#include <Windows.h>
#include <GL/GL.h>
#include <gl/GLU.h>
#include <GL/glut.h>

GLubyte resters[24] = 
{
	0xc0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xff,0x00,0xff,0x00,0xc0,0x00,0xc0,0x00,0xc0,0x00,
	0xff,0xc0,0xff,0xc0
};


void init(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2i(20, 20);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, resters);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, resters);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, resters);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0f);
	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(50 , 50);

	glutCreateWindow(argv[0]);

	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
*/