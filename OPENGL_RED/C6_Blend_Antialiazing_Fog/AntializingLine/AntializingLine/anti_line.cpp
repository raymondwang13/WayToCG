#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <stdio.h>

static float rotAngle = 0.0;

/* Initialize antialiasing for RGBA mode, including alpha blending ,
hint, and line width . Print out implimentation - specific 
info on line with granularity and width */
static void init(void)
{
	GLfloat values[2];
	
	glGetFloatv(GL_LINE_WIDTH_GRANULARITY, values);
	printf("GL_LINE_WIDTH_RANGE_GRANULARITY, values is %f \n", values[0]);
	
	glGetFloatv(GL_LINE_WIDTH_RANGE, values);
	printf("GL_LINE_WIDTH_RANGE, values are %f,  %f\n",values[0], values[1]);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

	glLineWidth(100.0);

	glClearColor(0.0, 0.0, 0.0, 0.0);
}

// draw 2 diagonal lines to form an X
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(-rotAngle, 0.0, 0.0, 0.1);
	glBegin(GL_LINES);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();
	glPopMatrix();

	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotatef(rotAngle, 0.0, 0.0, 0.1);
	glBegin(GL_LINES);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, -0.5);
	glEnd();
	glPopMatrix();

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
		glOrtho(-1.5, 1.5, -1.5 * aspect, 1.5 * aspect, -10.0, 10.0);
	}
	else
	{
		aspect = 1 / aspect;
		glOrtho(-1.5 * aspect, 1.5 * aspect, -1.5, 1.5, -10.0, 10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r':
	case 'R':
		rotAngle = rotAngle + 20.0;
		if (rotAngle >= 360.0)
		{
			rotAngle = 0.0;
		}
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
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("AntiLine");

	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}