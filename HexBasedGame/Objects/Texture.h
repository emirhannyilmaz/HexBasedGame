#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../Renderer/stb_image.h"
#include <vector>

class Texture {
public:
    Texture(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, bool flip, bool generateMipmaps);
    Texture(GLint format, GLenum sourceFormat, int width, int height, GLenum type, bool generateMipmaps);
    Texture(GLint format, GLenum sourceFormat, int width, int height, GLenum type, const void* data, bool generateMipmaps);
    Texture(std::vector<std::string> texturePaths, GLint format, GLenum sourceFormat, GLenum type, bool generateMipmaps);
    GLuint GetId();
    ~Texture();
private:
    GLuint id;
};