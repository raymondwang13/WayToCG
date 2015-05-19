/**
This function can be used for glutReshapeFunc(reshape) callback
*/

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble)w, 0.0, (GLdouble)h);
}