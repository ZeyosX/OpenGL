#include <iostream>
#include <gl/glut.h>
#include <Iseid/OpenGL/Utilities.h>
#include <vector>

#include <Iseid/Windowing/Window.h>
#include <Iseid/Windowing/WindowProperties.h>

using string = char[];

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
    const std::vector<Character>* characters{};
    bool underLined = false;
    float lineWidth{};
    Color3f lineColor{};
    int lineDistanceFromText{};
};

void glClearColor(const Color3f color, const float alpha = 1.0f)
{
    glClearColor(color.r, color.g, color.b, alpha);
}

void drawText(const Text& text)
{
    const auto characters = *text.characters;
    const unsigned int size = characters.size();
    for (unsigned int i = 0; i < size; i++)
    {
        glColor3f(characters[i].color.r, characters[i].color.g, characters[i].color.b);
        glRasterPos2i(characters[i].position.x, characters[i].position.y);
        glutBitmapCharacter(characters[i].font, characters[i].character);
    }
}

void drawLines(const Text& text)
{
    if (text.characters->empty() || !text.underLined)
    {
        return;
    }
    const auto characters = *text.characters;
    if (text.underLined)
    {
        glLineWidth(text.lineWidth);
        glBegin(BeginMode::Lines);
        glColor3f(text.lineColor.r, text.lineColor.g, text.lineColor.b);
        glVertex2i(characters[0].position.x, characters[0].position.y - text.lineDistanceFromText);
        glVertex2i(
            characters[characters.size() - 1].position.x + static_cast<int>(characters.size() * .5),
            characters[0].position.y - text.lineDistanceFromText
        );
    }
}

void init()
{
    glClearColor(1, 2, 3, 1);
    glMatrixMode(MatrixModes::Projection);
    glOrtho(0, 80, 0, 20, 0, 20);
}

void display()
{
    glClear(AttributeMask::ColorBufferBit);

    const std::vector<Character> helloCharacters =
    {
        Character('H', Fonts::TimesRoman_24, Vector2(40, 15), Colors::Red),
        Character('E', Fonts::TimesRoman_24, Vector2(43, 15), Colors::Black),
        Character('L', Fonts::TimesRoman_24, Vector2(46, 15), Colors::Red),
        Character('L', Fonts::TimesRoman_24, Vector2(49, 15), Colors::Black),
        Character('O', Fonts::TimesRoman_24, Vector2(52, 15), Colors::Red),
    };

    const std::vector<Character> worldCharacters =
    {
        Character('W', Fonts::TimesRoman_24, Vector2(40, 5), Colors::Green),
        Character('O', Fonts::TimesRoman_24, Vector2(43, 5), Colors::Blue),
        Character('R', Fonts::TimesRoman_24, Vector2(46, 5), Colors::Yellow),
        Character('L', Fonts::TimesRoman_24, Vector2(49, 5), Colors::Red),
        Character('D', Fonts::TimesRoman_24, Vector2(52, 5), Colors::Black),
    };

    const std::vector<Character> nameCharacters =
    {
        Character('O', Fonts::TimesRoman_24, Vector2(40, 2), Colors::Black),
        Character('M', Fonts::TimesRoman_24, Vector2(43, 2), Colors::Black),
        Character('A', Fonts::TimesRoman_24, Vector2(46, 2), Colors::Black),
        Character('R', Fonts::TimesRoman_24, Vector2(49, 2), Colors::Black),
    };

    const Text helloText = {&helloCharacters, true, 10, Colors::Black, 1};
    const Text worldText = {&worldCharacters, true, 15, Colors::Red, 1};
    const Text nameText = {&nameCharacters, true, 20, Colors::Green, 1};


    drawText(helloText);
    drawText(worldText);
    drawText(nameText);

    drawLines(helloText); // Todo : inline draw line function inside drawText
    drawLines(worldText);
    drawLines(nameText);


    glEnd();
    glFlush();
}


// auto main(int argc, char** argv) -> int
// {
//     constexpr auto displayMode = DisplayModeBitMask::Single | DisplayModeBitMask::RGB;
//
//     string title = "Hello World";
//     const WindowProperties properties(600, 50, 800, 600, title);
//     const Window window(&argc, argv, displayMode, properties);
//
//     window.Run(init, display);
//
//     return 0;
// }
