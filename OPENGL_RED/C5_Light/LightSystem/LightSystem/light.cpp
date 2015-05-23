#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <GL/GLU.h>
/*
void init(void)
{
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};
	GLfloat light_position[] = {2.0, 2.0, 2.0, 0.0};
	GLfloat white_light[] = {2.0, 2.0, 2.0, 1.0};
	GLfloat lmodel_ambient[] = {0.9, 0.5, 0.3, 1.0};


	GLfloat light1_ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light1_position[] = {-2.0, 2.0, 1.0, 1.0};
	GLfloat spot_direction[] = {-1.0, -1.0, 0.0, 0.0};

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);



	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0, 100, 80);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	{
		glOrtho(-3, 3, -3*(GLfloat)h/(GLfloat)w, 3.0*(GLfloat)h/(GLfloat)w, -20.0, 20.0);
	}
	else
	{
		glOrtho(-3*(GLfloat)h/(GLfloat)w, 3*(GLfloat)h/(GLfloat)w, -3, 3, -20, 20.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
	glutMainLoop();

	return 0;
}
*/
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







