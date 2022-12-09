#include "ShaderClass.h"

auto get_file_contents(const char* filename) -> std::string
{
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents; in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    throw errno;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    const std::string vertexCode = get_file_contents(vertexFile);
    const std::string fragmentCode = get_file_contents(fragmentFile);
    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); //It's stored as a reference
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader); //To compile the shader into a machine code and send it to the GPU

    const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //It's stored as a reference
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader); //To compile the shader into a machine code and send it to the GPU

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate() const
{
    glUseProgram(ID);
}

void Shader::Delete() const
{
    glDeleteProgram(ID);
}


