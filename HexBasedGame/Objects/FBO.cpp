#include "FBO.h"

FBO::FBO(GLenum colorAttachmentToDraw) {
    glGenFramebuffers(1, &id);
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glDrawBuffer(colorAttachmentToDraw);
}

void FBO::Bind(int width, int height) {
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    glViewport(0, 0, width, height);
}

void FBO::CreateTextureAttachment(int width, int height, GLenum colorAttachment) {
    texture = new Texture(GL_RGB, GL_RGB, width, height, GL_UNSIGNED_BYTE, false);
    glFramebufferTexture(GL_FRAMEBUFFER, colorAttachment, texture->GetId(), 0);
}

void FBO::CreateDepthTextureAttachment(int width, int height) {
    depthTexture = new Texture(GL_DEPTH_COMPONENT32, GL_DEPTH_COMPONENT, width, height, GL_FLOAT, false);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture->GetId(), 0);
}

void FBO::CreateDepthBufferAttachment(int width, int height) {
    glGenRenderbuffers(1, &depthBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBuffer);
}

void FBO::Unbind() {
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "ERROR::FBO::FBO_IS_NOT_COMPLETE" << std::endl;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, Window::GetWidth(), Window::GetHeight());
}

Texture* FBO::GetTexture() {
    return texture;
}

Texture* FBO::GetDepthTexture() {
    return depthTexture;
}

GLuint FBO::GetDepthBuffer() {
    return depthBuffer;
}

FBO::~FBO() {
    glDeleteFramebuffers(1, &id);
    delete texture;
    if (depthTexture != NULL) {
        delete depthTexture;
    }
    glDeleteRenderbuffers(1, &depthBuffer);
}
