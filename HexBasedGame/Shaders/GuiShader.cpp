#include "GuiShader.h"

GuiShader::GuiShader(const char* vertexShaderPath, const char* fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	modelLoc = GetUniformLocation("model");
}

void GuiShader::LoadModelMatrix(glm::mat4 matrix) {
	LoadMatrix4f(modelLoc, matrix);
}