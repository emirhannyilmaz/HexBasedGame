#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../../IO/Window.h"
#include "../../Objects/Texture.h"
#include "../../Objects/FBO.h"

class WaterFrameBuffers {
public:
    WaterFrameBuffers();
    void InitializeReflectionFrameBuffer();
    void InitializeRefractionFrameBuffer();
    void BindReflectionFrameBuffer();
    void BindRefractionFrameBuffer();
    void UnbindCurrentFrameBuffer();
    Texture* GetReflectionTexture();
    Texture* GetRefractionTexture();
    Texture* GetRefractionDepthTexture();
    ~WaterFrameBuffers();
private:
    static int REFLECTION_WIDTH;
    static int REFLECTION_HEIGHT;
    static int REFRACTION_WIDTH;
    static int REFRACTION_HEIGHT;
    FBO* reflectionFrameBuffer = NULL;
    FBO* refractionFrameBuffer = NULL;
};