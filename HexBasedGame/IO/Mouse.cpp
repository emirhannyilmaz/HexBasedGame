#include "Mouse.h"

float Mouse::mouseSensitivity = 0.005f;
float Mouse::mouseWheelSensitivity = 1.0f;
bool Mouse::firstMouse = true;
float Mouse::x = 0.0f;
float Mouse::y = 0.0f;
float Mouse::lastX = 0.0f;
float Mouse::lastY = 0.0f;
float Mouse::previousDx = 0.0f;
float Mouse::previousDy = 0.0f;
float Mouse::dx = 0.0f;
float Mouse::dy = 0.0f;
float Mouse::previousMouseWheel = 0.0f;
float Mouse::mouseWheel = 0.0f;
GLFWwindow* Mouse::window = NULL;

void Mouse::Setup(GLFWwindow* window) {
    Mouse::window = window;
}

void Mouse::MousePositionCallback(GLFWwindow* window, double xPos, double yPos) {
    if (firstMouse) {
        Mouse::lastX = xPos;
        Mouse::lastY = yPos;
        Mouse::firstMouse = false;
    }

    Mouse::dx = xPos - Mouse::lastX;
    Mouse::dy = Mouse::lastY - yPos;
    Mouse::lastX = xPos;
    Mouse::lastY = yPos;
    Mouse::x = xPos;
    Mouse::y = yPos;
}

void Mouse::MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
    Mouse::mouseWheel = yOffset;
}

float Mouse::GetX() {
    return x;
}

float Mouse::GetY() {
    return y;
}

float Mouse::GetDx() {
    if (Mouse::previousDx == Mouse::dx) {
        return 0.0f;
    }

    Mouse::previousDx = Mouse::dx;

    return Mouse::dx * mouseSensitivity;
}

float Mouse::GetDy() {
    if (Mouse::previousDy == Mouse::dy) {
        return 0.0f;
    }

    Mouse::previousDy = Mouse::dy;

    return Mouse::dy * mouseSensitivity;
}

float Mouse::GetMouseWheel() {
    if (Mouse::previousMouseWheel == Mouse::mouseWheel) {
        return 0.0f;
    }

    Mouse::previousMouseWheel = Mouse::mouseWheel;

    return Mouse::mouseWheel * mouseWheelSensitivity;
}

bool Mouse::GetMouseButtonDown(int button) {
    return glfwGetMouseButton(Mouse::window, button) == GLFW_PRESS;
}
