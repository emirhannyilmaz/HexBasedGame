#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../IO/Window.h"
#include "Texture.h"

class FBO {
public:
    FBO(GLenum colorAttachmentToDraw);
    void Bind(int width, int height);
    void CreateTextureAttachment(int width, int height, GLenum colorAttachment);
    void CreateDepthTextureAttachment(int width, int height);
    void CreateDepthBufferAttachment(int width, int height);
    void Unbind();
    Texture* GetTexture();
    Texture* GetDepthTexture();
    GLuint GetDepthBuffer();
    ~FBO();
private:
    GLuint id;
    Texture* texture = NULL;
    Texture* depthTexture = NULL;
    GLuint depthBuffer;
};