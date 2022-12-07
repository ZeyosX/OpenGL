#include <Iseid/Windowing/WindowProperties.h>


WindowProperties::WindowProperties(const int pos_x, const int pos_y, const int width, const int height, char* title) :
    pos_x(pos_x),
    pos_y(pos_y),
    width(width),
    height(height),
    title(title)
{   }


WindowProperties::~WindowProperties()
= default;
