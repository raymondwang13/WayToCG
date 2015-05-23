#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <GL/GLU.h>

static int spin = 0;
void init(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	GLfloat position[] = {0, 0, 1.5, 1};
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslated(0, 0, -5);

	glPushMatrix();
	glRotated((GLdouble)spin, 1, 0, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glTranslated(0, 0, 1.5);
	glDisable(GL_LIGHTING);
	glColor3f(0, 1, 1);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glutSolidTorus(0.275, 0.85, 8, 15);
	glPopMatrix();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, (GLfloat)w / (GLfloat)h, 1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button , int state, int x , int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			spin = (spin + 30) % 360;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 150);
	glutInitWindowSize(500, 500);
	glutCreateWindow("light");
	
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}

/*
// create static light source
GLfloat light_pposition[] = {1, 1, 1, 1};
glLightfv(GL_LIGHT0, GL_POSITION, light_pposition);
*/

/* create move light
static GLdouble spin;
void ddisplay(void)
{
	GLfloat light_position = {0, 0, 1.5, 1};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		gluLookAt(0,0,5, 0,0,0, 0,1,0);
		glPushMatrix();
			glRotated(spin, 1, 0, 0);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glPopMatrix();
		glutSolidSphere(0.275, 0.85, 8, 15);
	glPopMatrix();
	glFlush();
}
*/