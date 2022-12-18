#pragma once
#include "EBO.h"
#include "VBO.h"
#include "Vector3.h"

class GameObject
{
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    GLfloat* vertices;
    GLuint* indices{};
    GLsizeiptr verticesSize;
    GLsizeiptr indicesSize;
    VBO* vbo;
    EBO* ebo;
    
    GameObject(Vector3 position, Vector3 rotation, Vector3 scale,
        GLfloat* vertices, GLuint* indices,
        GLsizeiptr verticesSize, GLsizeiptr indicesSize);
    virtual ~GameObject();
    virtual void draw();
};
