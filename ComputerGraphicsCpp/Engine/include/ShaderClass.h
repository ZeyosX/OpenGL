﻿#pragma once
#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

auto get_file_contents(const char* filename) -> std::string;

class Shader
{
public:
    GLuint ID;
    Shader(const char* vertexFile, const char* fragmentFile);

    void Activate() const;
    void Delete() const;
};

#endif // !SHADER_CLASS_H
