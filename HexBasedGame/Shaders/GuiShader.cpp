#include "GuiShader.h"

GuiShader::GuiShader(const char* vertexShaderPath, const char* fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	modelLoc = GetUniformLocation("model");
	isHighlightedLoc = GetUniformLocation("isHighlighted");
}

void GuiShader::LoadModelMatrix(glm::mat4 matrix) {
	LoadMatrix4f(modelLoc, matrix);
}

void GuiShader::LoadIsHighlighted(bool value) {
	LoadBoolean(isHighlightedLoc, value);
}