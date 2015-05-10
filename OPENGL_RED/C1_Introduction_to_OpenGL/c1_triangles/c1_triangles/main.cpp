#include <iostream>
using namespace std;

#include "vgl.h"
#include "LoadShaders.h"

enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

#pragma comment(lib, "E:/WayToCG/OpenGLLibs/lib/glew_static_vs2010_d.lib")

// ------------------------------------------------------------------------------
//
//	The init() routine is used to set up data for use later in the program
//
void init(void)
{
	// initializing our vertex-array objectsb
	glGenVertexArrays(NumVAOs,VAOs);
	glBindVertexArray(VAOs[Triangles]);

	// postion information about two triangles
	GLfloat vertices[NumVertices][2] = {
		{-0.90f, -0.90f},		// triangle1
		{0.85f, -0.90f},
		{-0.90f, 0.85f},
		{0.90f, -0.85f},
		{0.90f, 0.90f},		// triangle2
		{-0.85f, 0.90f}
	};

	// allocating vertex-buffer objects
	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);

	// Preparing to Send Data to OpenGL : Loading Data into a Buffer Object
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	ShaderInfo shaders[]={
		{GL_VERTEX_SHADER, "triangles.vert"},		// vertex shader
		{GL_FRAGMENT_SHADER, "triangles.frag"},		// fragment shader
		{GL_NONE,NULL}
	};
	// prepare shaders for a GPU: take care of reading the shader files and creating our OpenGL shader programs
	GLuint program = LoadShaders(shaders);

	glUseProgram(program);
	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);
}

// ------------------------------------------------------------------------------
//
//	The display() routine is what really does the rendering
//
void display(void)
{
	// clear the window

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	// render the two triangles
	glBindVertexArray(VAOs[Triangles]);

	// Sending Data to OpenGL
	//glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glDrawArrays(GL_TRIANGLE_FAN, 0, NumVertices);

	// present image to the screen
	glFlush();
}

// ------------------------------------------------------------------------------
//
//	main
//
int main(int argc,char**argv)
{
	// initializes the GLUT library
	glutInit(&argc, argv);

	// configures the type of window we want to use with our application
	glutInitDisplayMode(GLUT_RGBA);

	// specifies the size of the window
	glutInitWindowSize(512, 512);

	// specify the type of OpenGL context
	glutInitContextProfile(GLUT_CORE_PROFILE);
	
	//glutCreateWindow(argv[0]);
	glutCreateWindow("Raymond triangles");

	if(glewInit())
	{
		cerr<<"Unable to initialize GLEW......exiting"<<endl;
		exit(EXIT_FAILURE);
	}
	
	init();
	
	// display callback when the rendering is changed
	glutDisplayFunc(display);
	
	// event loop
	glutMainLoop();
}

