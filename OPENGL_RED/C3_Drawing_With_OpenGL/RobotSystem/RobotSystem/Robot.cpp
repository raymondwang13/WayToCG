#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

static int shoulder = 0;
static int elbow = 0;

// init clear color and shade mode
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// remember myself position
	glPushMatrix();
	glTranslatef(-1.0, 0, 0);
	glRotatef((GLfloat)shoulder, 0, 0, 1.0);
	glTranslatef(1.0, 0, 0);


	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(2.0);
	glPopMatrix();
	
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void reshaped(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	/* decided which matrix is the current matrix
	MatrixMode 
	#define GL_MODELVIEW                      0x1700
	#define GL_PROJECTION                     0x1701
	#define GL_TEXTURE                        0x1702
	*/
	glMatrixMode(GL_PROJECTION);
	// reset current matrix to unit matrix
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-5);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 's':
		shoulder = (shoulder + 5)%360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5)%360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5)%360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5)%360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}


int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Raymond");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshaped);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
