#include "Camera.h"

Camera::Camera(float fov, int width, int height, float _near, float _far, glm::vec3 _position, float _pitch, float _yaw, float _roll, float _distance, float _minDistance, float _maxDistance, float _angleAround) {
	position = _position;
	pitch = _pitch;
	yaw = _yaw;
	roll = _roll;
	distance = _distance;
	minDistance = _minDistance;
	maxDistance = _maxDistance;
	angleAround = _angleAround;
	projection = glm::perspective(glm::radians(fov), (float) width / (float) height, _near, _far);
	near = _near;
	far = _far;
}

glm::mat4 Camera::GetViewMatrix() {
	view = glm::rotate(identity, glm::radians(pitch), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, glm::radians(yaw), glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, glm::radians(roll), glm::vec3(0.0f, 0.0f, 1.0f));
	view = glm::translate(view, -position);
	return view;
}

glm::mat4 Camera::GetProjectionMatrix() {
	return projection;
}

float Camera::GetNear() {
	return near;
}

float Camera::GetFar() {
	return far;
}

void Camera::HandleInput() {
	static glm::vec3 tempPos = glm::vec3(0.0f, 0.0f, 0.0f);

	if (Mouse::GetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {
		tempPos -= direction * Mouse::GetDy() * Window::GetDeltaTime();
		tempPos -= right * -Mouse::GetDx() * Window::GetDeltaTime();
	}
	else if (Mouse::GetMouseButton(GLFW_MOUSE_BUTTON_RIGHT)) {
		angleAround += Mouse::GetDx() * Window::GetDeltaTime();
	}
	else {
		distance -= Mouse::GetMouseWheel();
		if (distance <= minDistance) {
			distance = minDistance;
		}
		if (distance >= maxDistance) {
			distance = maxDistance;
		}
	}

	float verticalDistance = glm::sin(glm::radians(pitch)) * distance;
	float horizontalDistance = glm::cos(glm::radians(pitch)) * distance;

	float zOffset = (horizontalDistance * glm::cos(glm::radians(angleAround)));
	float xOffset = (horizontalDistance * glm::sin(glm::radians(angleAround)));

	direction.x = xOffset;
	direction.z = zOffset;
	direction = glm::normalize(direction);

	right = glm::normalize(glm::cross(up, direction));

	position.y = verticalDistance;
	position.z = tempPos.z - zOffset;
	position.x = tempPos.x - xOffset;

	yaw = 180.0f - angleAround;
}

glm::vec3 Camera::GetPosition() {
	return position;
}

void Camera::SetPosition(glm::vec3 _position) {
	position = _position;
}

void Camera::InvertPitch() {
	pitch = -pitch;
}
