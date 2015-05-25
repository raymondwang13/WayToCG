#include <iostream>
#include <GL/glew.h> 
#include <GL/glut.h> 
#include <GL/GL.h>

// Initialize color map and fog set screen clear color

#define RAMPSTART 12

static void init(void)
{
	int i;

	glEnable(GL_DEPTH_TEST);

	for (i = 0; i< NUMCOLORS; ++i)
	{
		GLfloat shade;
		shade = (GLfloat)(NUMCOLORS - i)/(GLfloat)NUMCOLORS;
		glutSetColor(RAMPSTART + i, shade, shade, shade);
	}
	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogi(GL_FOG_INDEX, NUMCOLORS);
	glFogf(GL_FOG_START, 1.0);
	glFogf(GL_FOG_END, 6.0);
	glHint(GL_FOG_HINT, GL_NICEST);
	glClearIndex((GLfloat)(NUMCOLORS + RAMPSTART - 1));	
}

static void renderSphere(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidSphere(0.4, 16, 16);
	glPopMatrix();
}

/*
display() draws 5 shperes at different z positions.
*/
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glIndexi(RAMPSTART);

	renderSphere(-2, -0.5, -1.0);
	renderSphere(-1.0, -0.5, - 2.0);
	renderSphere(0, -0.5, -3.0);
	renderSphere(1.0, -0.5, -4.0);
	renderSphere(2.0, -0.5, -5.0);

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspect = (GLfloat)h / (GLfloat)w;
	if (w <= h)
	{
		glOrtho(-2.5, 2.5, -2.5 * aspect, 2.5 * aspect, -10.0, 10.0);
	}
	else
	{
		aspect = 1 / aspect;
		glOrtho(-2.5 * aspect, 2.5 * aspect, -2.5, 2.5, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27: // Escape key
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GL_INDEX|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("FogIndex");

	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}