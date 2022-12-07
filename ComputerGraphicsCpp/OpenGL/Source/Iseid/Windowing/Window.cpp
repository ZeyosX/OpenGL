#include <Iseid/Windowing/Window.h>

#include <gl/glut.h>


Window::Window(int* argc, char** argv, const unsigned displayMode, const WindowProperties properties):
    m_argc(argc),
    m_argv(argv), m_displayMode(displayMode), m_windowProperties(properties)
{
}

void Window::Run(void (*initFunction)(), void (*displayFunction)()) const
{
    glutInit(m_argc, m_argv);
    glutInitDisplayMode(m_displayMode);
    glutInitWindowPosition(m_windowProperties.pos_x, m_windowProperties.pos_y);
    glutInitWindowSize(m_windowProperties.width, m_windowProperties.height);
    glutCreateWindow(m_windowProperties.title);
    initFunction();

    glutDisplayFunc(displayFunction);
    glutMainLoop();
}

Window::~Window()
= default;
