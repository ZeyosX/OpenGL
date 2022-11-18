#pragma once

namespace OpenGL_Enums
{
    struct DisplayModeBitMask
    {
        static constexpr unsigned int RGB = 0;
        static constexpr unsigned int RGBA = GLUT_RGB;
        static constexpr unsigned int Index = 1;
        static constexpr unsigned int Single = 0;
        static constexpr unsigned int Double = 2;
        static constexpr unsigned int Accum = 4;
        static constexpr unsigned int Alpha = 8;
        static constexpr unsigned int Depth = 16;
        static constexpr unsigned int Stencil = 32;
#if (GLUT_API_VERSION >= 2)
        static constexpr unsigned int Multisample = 128;
        static constexpr unsigned int Stereo = 256;
#endif
#if (GLUT_API_VERSION >= 3)
        static constexpr unsigned int Luminance = 512;
#endif
    };

    struct MatrixModes
    {
        static constexpr GLenum ModelView = 0x1700U;
        static constexpr GLenum Projection = 0x1701U;
        static constexpr GLenum Texture = 0x1702U;
    };

    struct BeginMode
    {
        static constexpr GLenum Points = 0x0000U;
        static constexpr GLenum Lines = 0x0001U;
        static constexpr GLenum LineLoop = 0x0002U;
        static constexpr GLenum LineStrip = 0x0003U;
        static constexpr GLenum Triangles = 0x0004U;
        static constexpr GLenum TriangleStrip = 0x0005U;
        static constexpr GLenum TriangleFan = 0x0006U;
        static constexpr GLenum Quads = 0x0007U;
        static constexpr GLenum QuadStrip = 0x0008U;
        static constexpr GLenum Polygon = 0x0009U;
    };

    struct AttributeMask
    {
        static constexpr int CurrentBit = 0x00000001;
        static constexpr int PointBit = 0x00000002;
        static constexpr int LineBit = 0x00000004;
        static constexpr int PolygonBit = 0x00000008;
        static constexpr int PolygonStippleBit = 0x00000010;
        static constexpr int PixelModeBit = 0x00000020;
        static constexpr int LightingBit = 0x00000040;
        static constexpr int FogBit = 0x00000080;
        static constexpr int DepthBufferBit = 0x00000100;
        static constexpr int AccumBufferBit = 0x00000200;
        static constexpr int StencilBufferBit = 0x00000400;
        static constexpr int ViewportBit = 0x00000800;
        static constexpr int TransformBit = 0x00001000;
        static constexpr int EnableBit = 0x00002000;
        static constexpr int ColorBufferBit = 0x00004000;
        static constexpr int HintBit = 0x00008000;
        static constexpr int EvalBit = 0x00010000;
        static constexpr int ListBit = 0x00020000;
        static constexpr int TextureBit = 0x00040000;
        static constexpr int ScissorBit = 0x00080000;
        static constexpr int AllAttribBits = 0x000fffff;
    };


    struct Fonts
    {
        static constexpr void* TimesRoman_10 = reinterpret_cast<void*>(4);
        static constexpr void* TimesRoman_24 = reinterpret_cast<void*>(5);
        static constexpr void* Helvetica_10 = reinterpret_cast<void*>(6);
        static constexpr void* Helvetica_12 = reinterpret_cast<void*>(7);
        static constexpr void* Helvetica_18 = reinterpret_cast<void*>(8);
    };
}
