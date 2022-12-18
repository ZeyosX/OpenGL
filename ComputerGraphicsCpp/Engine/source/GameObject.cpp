#include "GameObject.h"

GameObject::GameObject(const Vector3 position, const Vector3 rotation, const Vector3 scale,
                       GLfloat* vertices, GLuint* indices, const GLsizeiptr verticesSize,
                       const GLsizeiptr indicesSize):
    position(position), rotation(rotation), scale(scale), verticesSize(verticesSize)
{
    this->vertices = new float[verticesSize];
    for (unsigned int i = 0; i < verticesSize / 4; ++i)
    {
        this->vertices[i] = vertices[i];
    }
    this->indices = new GLuint[indicesSize];
    for (unsigned int i = 0; i < indicesSize; ++i)
    {
        this->indices[i] = indices[i];
    }
    this->vbo = new VBO(this->vertices, this->verticesSize);
    this->ebo = new EBO(this->indices, indicesSize);
}

GameObject::~GameObject()
{
    delete this->vbo;
    delete this->ebo;
    delete[] this->vertices;
    delete[] this->indices;
}

static void Translate(GLfloat* vertices, const GLsizeiptr size, const Vector3 translation)
{
    for (unsigned int i = 0; i < size / 4; i += 5)
    {
        vertices[i] += translation.x;
        vertices[i + 1] += translation.y;
        vertices[i + 2] += translation.z;
    }
}

void GameObject::draw()
{
    Translate(vertices, verticesSize, position);
}
