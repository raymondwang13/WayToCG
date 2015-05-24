#include <iostream>
#include <windows.h>
#include <GL/glew.h>
#include <GL/glut.h>
using namespace std ;

void init(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0) ;
	glBlendFunc(GL_ONE, GL_ONE) ;
	glEnable(GL_BLEND) ;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT) ;
	glColor3f(0.0, 0.0, 1.0) ;
	glRectf(-0.5, -0.5, 0.5, 0.5) ;
	glFlush() ;
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h) ;
	glMatrixMode(GL_PROJECTION) ;
	glLoadIdentity() ;
	if(w<=h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
		1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0) ;
	else
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h,
		1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0) ;
	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity() ;
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'a':
	case 'A':
		//Note: glBlendEquation is a subset of GL_ARB_imaging, please call glGetString
		//first to confirm whether your video card support this extension.
		glBlendEquation(GL_FUNC_ADD) ;
		break ;
	case 's':
	case 'S':
		glBlendEquation(GL_FUNC_SUBTRACT) ;
		break ;
	case 'r':
	case 'R':
		glBlendEquation(GL_FUNC_REVERSE_SUBTRACT) ;
	case 'm':
	case 'M':
		glBlendEquation(GL_MIN) ;
		break ;
	case 'x':
	case 'X':
		glBlendEquation(GL_MAX) ;
		break ;
	case 27:
		exit(0) ;
		break ;
	}
	glutPostRedisplay() ;
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv) ;
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB) ;
	glutInitWindowSize(200, 200) ;
	glutCreateWindow("Blend") ;

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		MessageBoxA(NULL, "error", "My Window", 1) ;
	}
	//if the return value contains "GL_ARB_imaging " then you can use glBlendEquation
	const GLubyte *str = glGetString(GL_EXTENSIONS) ;
	cout << str << endl ;

	init() ;
	glutReshapeFunc(reshape) ;
	glutKeyboardFunc(keyboard) ;
	glutDisplayFunc(display) ;
	glutMainLoop() ;
	return 0 ;
}