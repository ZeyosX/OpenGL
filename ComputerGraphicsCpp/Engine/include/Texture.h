﻿#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"shaderClass.h"

class Texture
{
public:
    GLuint ID{};
    GLenum type;
    Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    // Assigns a texture unit to a texture
    static void texUnit(const Shader& shader, const char* uniform, GLuint unit);
    // Binds a texture
    void Bind() const;
    // Unbinds a texture
    void Unbind() const;
    // Deletes a texture
    void Delete() const;
};
#endif