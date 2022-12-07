#pragma once

class WindowProperties
{
public:
    WindowProperties(int pos_x, int pos_y, int width, int height, char* title);
    ~WindowProperties();
    int pos_x;
    int pos_y;
    int width;
    int height;
    char* title;
};
