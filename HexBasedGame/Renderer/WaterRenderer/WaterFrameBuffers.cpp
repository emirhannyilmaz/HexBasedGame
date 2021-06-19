#include "WaterFrameBuffers.h"

int WaterFrameBuffers::REFLECTION_WIDTH = 1920 / 4;
int WaterFrameBuffers::REFLECTION_HEIGHT = 1080 / 4;
int WaterFrameBuffers::REFRACTION_WIDTH = 1920;
int WaterFrameBuffers::REFRACTION_HEIGHT = 1080;

WaterFrameBuffers::WaterFrameBuffers() {
    InitializeReflectionFrameBuffer();
    InitializeRefractionFrameBuffer();
}
void WaterFrameBuffers::InitializeReflectionFrameBuffer() {
    reflectionFrameBuffer = new FBO(GL_COLOR_ATTACHMENT0);
    reflectionFrameBuffer->Bind(0, 0);
    reflectionFrameBuffer->CreateTextureAttachment(WaterFrameBuffers::REFLECTION_WIDTH, WaterFrameBuffers::REFLECTION_HEIGHT, GL_COLOR_ATTACHMENT0);
    reflectionFrameBuffer->CreateDepthBufferAttachment(WaterFrameBuffers::REFLECTION_WIDTH, WaterFrameBuffers::REFLECTION_HEIGHT);
    reflectionFrameBuffer->Unbind();
}

void WaterFrameBuffers::InitializeRefractionFrameBuffer() {
    refractionFrameBuffer = new FBO(GL_COLOR_ATTACHMENT0);
    refractionFrameBuffer->Bind(0, 0);
    refractionFrameBuffer->CreateTextureAttachment(WaterFrameBuffers::REFRACTION_WIDTH, WaterFrameBuffers::REFRACTION_HEIGHT, GL_COLOR_ATTACHMENT0);
    refractionFrameBuffer->CreateDepthTextureAttachment(WaterFrameBuffers::REFRACTION_WIDTH, WaterFrameBuffers::REFRACTION_HEIGHT);
    refractionFrameBuffer->Unbind();
}

void WaterFrameBuffers::BindReflectionFrameBuffer() {
    reflectionFrameBuffer->Bind(WaterFrameBuffers::REFLECTION_WIDTH, WaterFrameBuffers::REFLECTION_HEIGHT);
}

void WaterFrameBuffers::BindRefractionFrameBuffer() {
    refractionFrameBuffer->Bind(WaterFrameBuffers::REFRACTION_WIDTH, WaterFrameBuffers::REFRACTION_HEIGHT);
}

void WaterFrameBuffers::UnbindCurrentFrameBuffer() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, Window::GetWidth(), Window::GetHeight());
}

Texture* WaterFrameBuffers::GetReflectionTexture() {
    return reflectionFrameBuffer->GetTexture();
}

Texture* WaterFrameBuffers::GetRefractionTexture() {
    return refractionFrameBuffer->GetTexture();
}

Texture* WaterFrameBuffers::GetRefractionDepthTexture() {
    return refractionFrameBuffer->GetDepthTexture();
}

WaterFrameBuffers::~WaterFrameBuffers() {
    delete refractionFrameBuffer;
    delete reflectionFrameBuffer;
}
