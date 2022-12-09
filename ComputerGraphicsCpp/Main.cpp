#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"

//Fragment Shader source code


auto main() -> int
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /*  --------------------
     *  |        1          |
     *  |                   |
     *  |                   |
     *  | -1     0         1|
     *  |                   |
     *  |        -1         |
     *  -------------------- */
    GLfloat vertices[] =
    {
        -0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f, // Lower left corner
        0.5f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f, // Lower right corner
        0.0f, 0.5f * static_cast<float>(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
        -0.5f / 2, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f, // Inner left
        0.5f / 2, 0.5f * static_cast<float>(sqrt(3)) / 6, 0.0f, // Inner right
        0.0f, -0.5f * static_cast<float>(sqrt(3)) / 3, 0.0f // Inner down
    };

    // Indices for vertices order
    GLuint indices[] =
    {
        0, 3, 5, // Lower left triangle
        3, 2, 4, // Lower right triangle
        5, 4, 1 // Upper triangle
    };

    const auto window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();


    glViewport(0, 0, 800, 800);

    const Shader shaderProgram("default.vert", "default.frag");

    VAO VAO1;
    VAO1.Bind();

    const VBO VBO1(vertices, sizeof(vertices));
    const EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();

        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        //To swap the color buffer that has been used to draw in this iteration and show it as output to the screen
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
