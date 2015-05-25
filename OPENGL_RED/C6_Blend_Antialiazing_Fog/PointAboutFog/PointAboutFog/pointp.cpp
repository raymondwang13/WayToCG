#include <iostream>
#include <GL/glew.h> 
#include <GL/glut.h> 
#include <GL/GL.h>

static GLfloat f1 = 0.25;
static GLfloat f2 = 0.25;
static GLfloat f3 = 0.5;
static GLfloat constant[3] = {1.0, 0.0, 0.0};
static GLfloat linear[3] = {0.0, 0.12, 0.0};
static GLfloat quadratic[3] = {0.0, 0.0, 0.01};

// Initialize fog
static void init(void)
{
	GLfloat fogColor[4] = {0, 0.25, 0.25, 1.0};
	f1 = 1.0f;
	f2 = 5.0;
	f3 = 10.0f;

	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE, GL_EXP);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.25);
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogi(GL_FOG_COORD_SRC, GL_FOG_COORD);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// fog color
	glClearColor(0.0, 0.25, 0.25, 1.0);	
}

// display() draws a traiangle at an angle
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.75, 0.0);
	glBegin(GL_TRIANGLES);
	//glFogCoordf(f1);
	PFNGLFOGCOORDFPROC(f1);
	glVertex3f(2.0, -2.0, 0.0);
	PFNGLFOGCOORDFPROC(f2);
	glVertex3f(-2.0, 0.0, -5.0);
	PFNGLFOGCOORDFPROC(f3);
	glVertex3f(0.0, 2.0, -10.0);
	glEnd();

	glutSwapBuffers();
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
	case 'c':
		//glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, constant);
		PFNGLPOINTPARAMETERFVPROC(GL_POINT_DISTANCE_ATTENUATION, constant);
		glutPostRedisplay();
		break;
	case 'l':
		PFNGLPOINTPARAMETERFVPROC(GL_POINT_DISTANCE_ATTENUATION, linear);
		glutPostRedisplay();
		break;
	case 'q':
		PFNGLPOINTPARAMETERFVPROC(GL_POINT_DISTANCE_ATTENUATION, quadratic);
		glutPostRedisplay();
		break;
	case 'b':
		glMatrixMode(GL_MODELVIEW);
		glTranslatef(0.0, 0.0, -0.5);
		glutPostRedisplay();
	case 'f':
		glMatrixMode(GL_MODELVIEW);
		glTranslatef(0.0, 0.0, 0.5);
		glutPostRedisplay();
		break;
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
