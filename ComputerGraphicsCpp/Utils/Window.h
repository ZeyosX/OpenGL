#pragma once
#include <memory>

#include "WindowProperties.h"

class Window
{
    int* m_argc;
    char** m_argv;
    unsigned int m_displayMode;
    WindowProperties m_windowProperties;

public:
    Window(int* argc, char** argv, unsigned int displayMode, WindowProperties properties);
    ~Window();
    void Run(void (*initFunction)(), void (*displayFunction)()) const;
};
