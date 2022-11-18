#include <iostream>
#include <gl/glut.h>
#include <Utilities.h>

#include "Window.h"
#include "WindowProperties.h"

using string = char[];

// glColor3f(characters[x]->color.r, characters[x]->color.g, characters[x]->color.b);
// glRasterPos2f(characters[x]->position->x, characters[x]->position->y);
// glutBitmapCharacter(characters[x]->font, characters[x]->character);

void init();
void display();
void drawCharacter();


using namespace OpenGL_Enums;

struct Vector2
{
    Vector2(const int x, const int y) : x(x), y(y)
    {
    }

    int x, y;
};

struct Color3f
{
    float r, g, b;
};

struct Colors
{
    static constexpr Color3f Red = {1.0f, 0.0f, 0.0f};
    static constexpr Color3f Green = {0.0f, 1.0f, 0.0f};
    static constexpr Color3f Blue = {0.0f, 0.0f, 1.0f};
    static constexpr Color3f Yellow = {1.0f, 1.0f, 0.0f};
    static constexpr Color3f Cyan = {0.0f, 1.0f, 1.0f};
    static constexpr Color3f Magenta = {1.0f, 0.0f, 1.0f};
    static constexpr Color3f White = {1.0f, 1.0f, 1.0f};
    static constexpr Color3f Black = {0.0f, 0.0f, 0.0f};
};

class Character
{
public:
    Character(const char character, void* font, const Vector2 position, const Color3f color)
        : character(character), font(font), color(color), position(position)
    {
    }

    const char character;
    void* font;
    Color3f color;
    const Vector2 position;
};


struct Text
{
    Character* characters;
    bool underLined = false;
    float lineWidth;
    Color3f lineColor;
    unsigned int lineDistanceFromText;

    int charactersCount = sizeof(*characters) / sizeof(characters[0]);

    int lineStart = characters[0].position.x;
    int lineEnd = characters[charactersCount - 1].position.x;
};

void glClearColor(const Color3f color, const float alpha = 1.0f)
{
    glClearColor(color.r, color.g, color.b, alpha);
}


// void init()
// {
//     glClearColor(Colors::White, 0.3f);
//     glMatrixMode(MatrixModes::Projection);
//     gluOrtho2D(0, 40, 0, 20);
// }

// void display()
// {
//     glClear(AttributeMask::ColorBufferBit);


// auto characters = new Character[]
// {
//     Character('H', GLUT_BITMAP_TIMES_ROMAN_24, new Vector2(5.0f, 10.0f), Colors::Red),
//     Character('e', GLUT_BITMAP_TIMES_ROMAN_24, new Vector2(8.0f, 10.0f), Colors::Black),
//     Character('l', GLUT_BITMAP_TIMES_ROMAN_24, new Vector2(12.0f, 10.0f), Colors::Red),
//     Character('l', GLUT_BITMAP_TIMES_ROMAN_24, new Vector2(13.0f, 10.0f), Colors::Black),
//     Character('o', GLUT_BITMAP_TIMES_ROMAN_24, new Vector2(15.0f, 10.0f), Colors::Red),
// };
//
// unsigned int length = sizeof(characters) / sizeof(characters[0]);
// for (unsigned i = 0; i < length; i++)
// {
//     glColor3f(characters[i].color.r, characters[i].color.g, characters[i].color.b);
//     glRasterPos2f(characters[i].position->x, characters[i].position->y);
//     glutBitmapCharacter(characters[i].font, characters[i].character);
//     std::cout << characters[i].character << std::endl;
//     std::cout << characters[i].position->x << std::endl;
//     std::cout << characters[i].position->y << std::endl;
// }

//     glEnd();
//     glFlush();
// }

void init()
{
    glClearColor(1, 2, 3, 1);
    glMatrixMode(MatrixModes::Projection);
    glOrtho(0, 80, 0, 20, 0, 20);
}

void display()
{
    glClear(AttributeMask::ColorBufferBit);

    Character characters[] =
    {
        Character('H', Fonts::TimesRoman_24, Vector2(5, 10), Colors::Red),
        Character('E', Fonts::TimesRoman_24, Vector2(8, 10), Colors::Black),
        Character('L', Fonts::TimesRoman_24, Vector2(12, 10), Colors::Red),
        Character('L', Fonts::TimesRoman_24, Vector2(13, 10), Colors::Black),
        Character('O', Fonts::TimesRoman_24, Vector2(15, 10), Colors::Red),
    };

    Text text = {characters, false, 0, Colors::Black, 1};
    for (int i = 0; i < 5; i++)
    {
        glColor3f(text.characters[i].color.r, text.characters[i].color.g, text.characters[i].color.b);
        glRasterPos2i(text.characters[i].position.x, text.characters[i].position.y);
        glutBitmapCharacter(text.characters[i].font, text.characters[i].character);
    }

    glLineWidth(text.lineWidth);
    glBegin(BeginMode::Lines);
    glColor3f(text.lineColor.r, text.lineColor.g, text.lineColor.b);
    glVertex2i(text.lineStart, text.characters[0].position.y - text.lineDistanceFromText);
    glVertex2i(text.lineStart + text.lineEnd + 2, text.characters[text.charactersCount - 1].position.y - text.lineDistanceFromText);

    glEnd();
    glFlush();
}


auto main(int argc, char** argv) -> int
{
    constexpr auto displayMode = DisplayModeBitMask::Single | DisplayModeBitMask::RGB;

    string title = "HelloWorld";
    const WindowProperties properties(600, 50, 400, 400, title);
    const Window window(&argc, argv, displayMode, properties);

    window.Run(init, display);

    return 0;
}
