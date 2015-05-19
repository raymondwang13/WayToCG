#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

static int year = 0;
static int day  = 0;

// init clear color and shade mode
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	
	// remember myself position
	glPushMatrix();
	
	// draw sun
	glutWireSphere(1.0, 20, 16);
	// rotate with y-axix
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);

	// draw smaller planet
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);

	// go back to myself position
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
	gluLookAt(0.0,0.0,5.0,  0.0,0.0,0.0, 0.0,1.0,0.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'd':
		day = (day + 10)%360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10)%360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 10)%360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 10)%360;
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
	glutInitWindowSize(300, 300);
	glutCreateWindow("Raymond");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshaped);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}