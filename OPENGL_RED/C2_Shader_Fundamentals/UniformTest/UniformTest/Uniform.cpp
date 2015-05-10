/**  Initializing Uniform Variables in a Named Uniform Block  */
// Vertex and fragment shaders that share a block of uniforms named "Uniforms"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GLU.h>
#include "vgl.h"
#include <stdio.h>
#include "LoadShaders.h"

/*  Helper function to convert GLSL types to storage sizes */
size_t TypeSize(GLenum type)
{
	size_t size;

	#define CASE(Enum, Count, Type) \
	case Enum:	size = Count * sizeof(Type); break

	switch(type)
	{
		CASE(GL_FLOAT,			1,	GLfloat);
		CASE(GL_FLOAT_VEC2,		2,	GLfloat);
		CASE(GL_FLOAT_VEC3,		3,	GLfloat);
		CASE(GL_FLOAT_VEC4,		4,	GLfloat);
		CASE(GL_INT,				1,	GLfloat);
		CASE(GL_INT_VEC2,			2,	GLfloat);
		CASE(GL_INT_VEC3,			3,	GLfloat);
		CASE(GL_INT_VEC4,			4,	GLfloat);
		CASE(GL_UNSIGNED_INT,		1,	GLfloat);
		CASE(GL_UNSIGNED_INT_VEC2,	2,	GLfloat);
		CASE(GL_UNSIGNED_INT_VEC3,	3,	GLfloat);
		CASE(GL_UNSIGNED_INT_VEC4,	4,	GLfloat);
		CASE(GL_BOOL,				1,	GLboolean);
		CASE(GL_BOOL_VEC2,		2,	GLboolean);
		CASE(GL_BOOL_VEC3,		3,	GLboolean);
		CASE(GL_BOOL_VEC4,		4,	GLboolean);
		CASE(GL_FLOAT_MAT2,		4,	GLfloat);
		CASE(GL_FLOAT_MAT2x3,		6,	GLfloat);
		CASE(GL_FLOAT_MAT2x4,		8,	GLfloat);
		CASE(GL_FLOAT_MAT3,		9,	GLfloat);
		CASE(GL_FLOAT_MAT3x2,		6,	GLfloat);
		CASE(GL_FLOAT_MAT3x4,		12,	GLfloat);
		CASE(GL_FLOAT_MAT4,		16,	GLfloat);
		CASE(GL_FLOAT_MAT4x2,		8,	GLfloat);
		CASE(GL_FLOAT_MAT4x3,		12,	GLfloat);
		#undef CASE
		default:
		fprintf(stderr, "Unknown type: 0x%x\n", type);
		exit(EXIT_FAILURE);
		break;
	}

	return size;
}


#pragma comment(lib, "E:/WayToCG/OpenGLLibs/lib/glew_static_vs2010_d.lib")

void init()
{
	GLuint program;

	glClearColor(1, 0 , 0, 1);

	ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "uniforms.vert" },
		{ GL_FRAGMENT_SHADER, "uniforms.frag" },
		{ GL_NONE, NULL }
	};

	program = LoadShaders(shaders);
	glUseProgram(program);

	/* Initialize uniform values in uniform block "Uniforms" */
	GLuint uboIndex;
	GLint  uboSize;
	GLuint ubo;
	GLchar *buffer;

	/* Find the uniform buffer index for "Uniforms", and determine the block's sizes */
	uboIndex = glGetUniformBlockIndex(program, "Uniforms");
	glGetActiveUniformBlockiv(program, uboIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &uboSize);
	buffer = (GLchar*)malloc(uboSize);

	if (NULL == buffer)
	{
		fprintf(stderr, "Unable to allocate buffer \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		enum { Translation, Scale, Rotatioin, Enabled, NumUniforms };

		/* Values to be stored in the buffer object */
		GLfloat scale = 0.5;
		GLfloat translation[] = {0.1f, 0.1f, 0.0f};
		GLfloat rotation[] = {90.0f, 0.0f, 0.0f, 1.0f};
		GLboolean enabled = GL_TRUE;

		/* Since we know the names of the uniforms in our block , make an array of those values */
		const char* names[NumUniforms] = {
			"translation",
			"scale",
			"rotation",
			"enabled"
		};

		/* Query the necessary attributes to determine where in the buffer we should write the values */
		GLuint	indices[NumUniforms];
		GLint	size[NumUniforms];
		GLint	offset[NumUniforms];
		GLint	type[NumUniforms];

		glGetUniformIndices(program, NumUniforms, names, indices);
		glGetActiveUniformsiv(program, NumUniforms, indices, GL_UNIFORM_OFFSET, offset);
		glGetActiveUniformsiv(program, NumUniforms, indices, GL_UNIFORM_SIZE, size);
		glGetActiveUniformsiv(program, NumUniforms, indices, GL_UNIFORM_TYPE, type);

		/* Copy the uniform values into the buffer */
		memcpy(buffer + offset[(int)Scale], &scale, size[(int)Scale] * TypeSize(type[(int)Scale]));
		memcpy(buffer + offset[Translation], & translation, size[Translation] * TypeSize(type[Translation]));
		memcpy(buffer + offset[Rotatioin], & rotation, size[Rotatioin] * TypeSize(type[Rotatioin]));
		memcpy(buffer + offset[Enabled], & enabled, size[Enabled] * TypeSize(type[Enabled]));

		/* Create the uniform buffer, object, initialize its storage, and associated it with the shader program */
		glGenBuffers(1, &ubo);
		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, uboSize, buffer, GL_STATIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, uboIndex, ubo);
	}
	// do others
}

int main(int argc, char** argv)
{
	init();
	return 0;
}