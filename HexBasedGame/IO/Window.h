#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Mouse.h"
#include <string>
#include <cstring>
#include <sstream>

class Window {
public:
    int CreateWindow(int width, int height, const char* _title);
    static int GetWidth();
    static int GetHeight();
    static float GetDeltaTime();
    int ShouldClose();
    void CalculateDeltaTime();
    void DoStuff();
    ~Window();
private:
    GLFWwindow* window = NULL;
    static int width;
    static int height;
    const char* title;
    static float deltaTime;
    float lastFrame = 0.0f;
    bool first = true;
    float timer = 0.0f;
    int frames = 0;
};