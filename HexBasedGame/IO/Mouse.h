#pragma once

#include <iostream>
#include "Window.h"
#include <GLFW/glfw3.h>

class Mouse {
public:
    static void Setup(GLFWwindow* window);
    static void MousePositionCallback(GLFWwindow* window, double xPos, double yPos);
    static void MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
    static float mouseSensitivity;
    static float mouseWheelSensitivity;
    static bool firstMouse;
    static float x;
    static float y;
    static float lastX;
    static float lastY;
    static float previousDx;
    static float previousDy;
    static float dx;
    static float dy;
    static float mouseWheel;
    static GLFWwindow* window;
    static float GetX();
    static float GetY();
    static float GetDx();
    static float GetDy();
    static float GetMouseWheel();
    static bool GetMouseButton(int button);
    static bool GetMouseButtonDown(int button);
};