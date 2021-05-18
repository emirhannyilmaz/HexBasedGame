#pragma once

#include <iostream>
#include <string>
#include <glm/glm.hpp>

class Text {
public:
	Text(std::string _text, glm::vec2 _position, glm::vec2 _scale, glm::vec3 _color, bool _isActive);
	std::string GetText();
	void SetText(std::string _text);
	glm::vec2 GetPosition();
	void SetPosition(glm::vec2 _position);
	glm::vec2 GetScale();
	void SetScale(glm::vec2 _scale);
	glm::vec3 GetColor();
	void SetColor(glm::vec3 _color);
	bool GetIsActive();
	void SetIsActive(bool value);
private:
	std::string text;
	glm::vec2 position;
	glm::vec2 scale;
	glm::vec3 color;
	bool isActive;
};