#include "Window.h"

int Window::width = 0.0f;
int Window::height = 0.0f;
float Window::deltaTime = 0.0f;

int Window::CreateWindow(int width, int height, const char* _title) {
    if (!glfwInit()) {
        std::cout << "ERROR::GLFW::INITIALIZATION_FAILED" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(width, height, _title, NULL, NULL);

    Window::width = width;
    Window::height = height;
    title = _title;

    if (window == NULL) {
        std::cout << "ERROR::GLFW::WINDOW_CREATING_FAILED" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    Mouse::Setup(window);
    glfwSetCursorPosCallback(window, Mouse::MousePositionCallback);
    glfwSetScrollCallback(window, Mouse::MouseScrollCallback);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cout << "ERROR::GLEW::INITIALIZATION_FAILED" << std::endl;
        return -1;
    }

    glViewport(0, 0, width, height);

    return 0;
}

int Window::GetWidth() {
    return Window::width;
}

int Window::GetHeight() {
    return Window::height;
}

float Window::GetDeltaTime() {
    return deltaTime;
}

int Window::ShouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::CalculateDeltaTime() {
    float currentFrame = glfwGetTime() * 1000.0f;
    Window::deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    if (first) {
        timer = glfwGetTime() * 1000.0f;
        first = false;
    }
}

void Window::DoStuff() {
    glfwSwapBuffers(window);
    glfwPollEvents();

    frames++;
    if ((glfwGetTime() * 1000.0f) - timer >= 1000.0f) {
        std::stringstream ss;
        ss << title << " " << "[" << frames << " FPS]";
        glfwSetWindowTitle(window, ss.str().c_str());
        frames = 0;
        first = true;
    }
}

Window::~Window() {
    glfwTerminate();
}
