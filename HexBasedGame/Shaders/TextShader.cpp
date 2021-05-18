#include "TextShader.h"

TextShader::TextShader(const char* vertexShaderPath, const char* fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	projectionLoc = GetUniformLocation("projection");
	textColorLoc = GetUniformLocation("textColor");
}

void TextShader::LoadProjectionMatrix(glm::mat4 matrix) {
	LoadMatrix4f(projectionLoc, matrix);
}

void TextShader::LoadTextColor(glm::vec3 color) {
	LoadVector3f(textColorLoc, color);
}