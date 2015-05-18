#include <Windows.h>
#include <GL/GL.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(void)
{
	GLdouble equ1[] = {0, 1, 0, 0};
	GLdouble eql2[] = {1, 0, 0, 0};
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.5);

	glPushMatrix();
	glTranslatef(0, 0, -5);

	glClipPlane(GL_CLIP_PLANE0, equ1);
	glEnable(GL_CLIP_PLANE0);
	glClipPlane(GL_CLIP_PLANE1, eql2);
	glEnable(GL_CLIP_PLANE1);

	glRotatef(90, 1, 0, 0);
	glutWireSphere(1, 20, 16);
	glPopMatrix();


	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// Decide which matrix will be changed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(40, (GLsizei)w/(GLsizei)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("raymond wang");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}