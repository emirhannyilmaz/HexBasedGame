#include "Text.h"

Text::Text(std::string _text, glm::vec2 _position, glm::vec2 _scale, glm::vec3 _color, bool _isActive, bool _isCentered) {
	text = _text;
	position = _position;
	scale = _scale;
	color = _color;
	isActive = _isActive;
	isCentered = _isCentered;
}

std::string Text::GetText() {
	return text;
}

void Text::SetText(std::string _text) {
	text = _text;
}

glm::vec2 Text::GetPosition() {
	return position;
}

void Text::SetPosition(glm::vec2 _position) {
	position = _position;
}

glm::vec2 Text::GetScale() {
	return scale;
}

void Text::SetScale(glm::vec2 _scale) {
	scale = _scale;
}

glm::vec3 Text::GetColor() {
	return color;
}

void Text::SetColor(glm::vec3 _color) {
	color = _color;
}

bool Text::GetIsActive() {
	return isActive;
}

void Text::SetIsActive(bool value) {
	isActive = value;
}

bool Text::GetIsCentered() {
	return isCentered;
}

void Text::SetIsCentered(bool value) {
	isCentered = value;
}