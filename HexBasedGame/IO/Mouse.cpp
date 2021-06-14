#include "Mouse.h"

float Mouse::mouseSensitivity = 25.0f;
float Mouse::mouseWheelSensitivity = 10.0f;
bool Mouse::firstMouse = true;
float Mouse::x = 0.0f;
float Mouse::y = 0.0f;
float Mouse::lastX = 0.0f;
float Mouse::lastY = 0.0f;
float Mouse::previousDx = 0.0f;
float Mouse::previousDy = 0.0f;
float Mouse::dx = 0.0f;
float Mouse::dy = 0.0f;
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
	float value = Mouse::mouseWheel;
	Mouse::mouseWheel = 0.0f;

	return value * mouseWheelSensitivity;
}

bool Mouse::GetMouseButton(int button) {
	return glfwGetMouseButton(Mouse::window, button) == GLFW_PRESS;
}

bool Mouse::GetMouseButtonDown(int button) {
	static int oldState = GLFW_RELEASE;
	int newState = glfwGetMouseButton(Mouse::window, button);
	if (newState == GLFW_RELEASE && oldState == GLFW_PRESS) {
		oldState = newState;
		return true;
	} else {
		oldState = newState;
		return false;
	}
}