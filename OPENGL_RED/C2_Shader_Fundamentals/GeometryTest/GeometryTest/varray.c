static GLint vertices[] =
{
	25, 25, 
	100,325,
	175,25,
	175,325,
	250,25,
	325,325
};

static GLfloat colors[] = 
{
	1.0, 0.2, 0.2,
	0.2, 0.2, 1.0,
	0.8, 1.0, 0.2,
	0.75,0.75,0.75,
	0.35,0.35,0.35,
	0.5, 0.5, 0.5
};

glEnableClientState(GL_COLOR_ARRAY);
glEnableClientState(GL_VERTEX_ARRAY);

glColorPointer(3, GL_FLOAT, 0, colors);
glVertexPointer(2, GL_INT, 0, vertices);

glBegin(GL_TRIANGLES);

/*
glArrayElement(2) 
	==
glColor3f(colors + (2*3));
glVertex2iv(vertices + (2*2));
It's useful for accessing random element
*/
glArrayElement(2);
glArrayElement(3);
glArrayElement(5);

glEnd();

// -----------------------
//glDrawElements(GL_TRIANGLES, 3, GL_FLOAT, vertices)
glBegin(GL_TRIANGLES);
for(int i=0; i<3; i++)
{
	glArrayElement(vertices[i]);
}
glEnd();

static GLubyte frontIndices[] = {4, 5, 6, 7};
static GLubyte rightIndices[] = {1, 2, 6, 5};
static GLubyte bottomIndices[] = {0, 1, 5, 4};
static GLubyte backIndices[] = {0, 3, 2, 1};
static GLubyte leftIndices[] = {0, 4, 7, 3};
static GLubyte topIndices[] = {2, 3, 7, 6};

glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, frontIndices);
glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, rightIndices);
glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottomIndices);
glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, backIndices);
glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, leftIndices);
glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, topIndices);

// equal below

static GLubyte allIndices[] = { 4,5,6,7,1,26,5,0,1,5,4,0,3,2,1,0,4,7,3,2,3,7,6};
glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, allIndices);

//--------------------------------------------
static GLubyte oneIndices = {0, 1, 2, 3, 4, 5, 6};
static GLubyte twoIndices = {6, 7, 8, 9, 10, 11};
static GLsizei count[] = {7, 6};
static GLvoid* indices[2] = {oneIndices, twoIndices};

glMultiDrawElements(GL_LINE_STRIP, count, GL_UNSIGNED_BYTE, indices, 2);