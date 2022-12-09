#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
    GLuint ID{};
    VBO(const GLfloat* vertices, GLsizeiptr size);
    void Bind() const;
    static void Unbind();
    void Delete() const;
    
};
#endif
