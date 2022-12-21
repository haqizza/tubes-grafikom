#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include "include/glad/glad.h"
#include "VBO.h"

class VAO
{
public:
	GLuint ID;
	VAO();
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void LinkAttribAll(VBO& VBO);
	void Bind();
	void Unbind();
	void Delete();
};

#endif