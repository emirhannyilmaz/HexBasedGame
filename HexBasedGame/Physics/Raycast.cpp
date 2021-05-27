#include "Raycast.h"

Raycast::Raycast(Camera* _camera, float _rayRange, int _recursionCount, float _hexHeight) {
	rayRange = _rayRange;
	recursionCount = _recursionCount;
	hexHeight = _hexHeight;
	camera = _camera;
	projectionMatrix = _camera->GetProjectionMatrix();
	viewMatrix = _camera->GetViewMatrix();
}

glm::vec3 Raycast::GetCurrentRay() {
	return currentRay;
}

glm::vec3 Raycast::GetCurrentPoint() {
	return currentPoint;
}

void Raycast::Update() {
	viewMatrix = camera->GetViewMatrix();
	currentRay = CalculateRay();

	if (IntersectionInRange(0, rayRange)) {
		currentPoint = BinarySearch(0, 0, rayRange);
	} else {
		currentPoint = glm::vec3(0.0f, 0.0f, 0.0f);
	}
}

void Raycast::CheckForCollisions(std::vector<Entity*> entities, GuiTexture* buildMenuTexture, std::vector<GuiButton*> buildButtons, GuiTexture* hexInfoTexture, Text* hexNameText) {
	bool nothingsColliding = true;
	for (int i = 0; i < entities.size(); i++) {
		for (int j = 0; j < entities.at(i)->GetColliders().size(); j++) {
			if (Collision::IsPointInsideBox(currentPoint, entities.at(i)->GetColliders().at(j).GetVertices())) {
				if (!entities.at(i)->GetIsSelected()) {
					entities.at(i)->SetIsHighlighted(true);
				}
				if (Mouse::GetMouseButtonDown(0)) {
					bool entityWasSelected = false;
					if (!entities.at(i)->GetIsSelected()) {
						for (int i = 0; i < entities.size(); i++) {
							if (entities.at(i)->GetIsSelected()) {
								entities.at(i)->SetIsSelected(false);
								hexInfoTexture->SetIsActive(false);
								hexNameText->SetIsActive(false);
								buildMenuTexture->SetIsActive(false);
								for (int i = 0; i < buildButtons.size(); i++) {
									buildButtons.at(i)->SetIsActive(false);
								}
								entityWasSelected = true;
							}
						}
						if (!entityWasSelected) {
							entities.at(i)->SetIsSelected(true);
							hexInfoTexture->SetIsActive(true);
							hexNameText->SetIsActive(true);
							hexNameText->SetText(entities.at(i)->GetName());
							buildMenuTexture->SetIsActive(true);
							for (int i = 0; i < buildButtons.size(); i++) {
								buildButtons.at(i)->SetIsActive(true);
							}
						}
					} else {
						entities.at(i)->SetIsSelected(false);
						hexInfoTexture->SetIsActive(false);
						hexNameText->SetIsActive(false);
						buildMenuTexture->SetIsActive(false);
						for (int i = 0; i < buildButtons.size(); i++) {
							buildButtons.at(i)->SetIsActive(false);
						}
					}
				}
				break;
			} else {
				entities.at(i)->SetIsHighlighted(false);
			}
		}
	}
	if (nothingsColliding) {
		if (Mouse::GetMouseButtonDown(0)) {
			for (int i = 0; i < entities.size(); i++) {
				entities.at(i)->SetIsSelected(false);
				hexInfoTexture->SetIsActive(false);
				hexNameText->SetIsActive(false);
				buildMenuTexture->SetIsActive(false);
				for (int i = 0; i < buildButtons.size(); i++) {
					buildButtons.at(i)->SetIsActive(false);
				}
			}
		}
	}
}

glm::vec3 Raycast::CalculateRay() {
	float mouseX = Mouse::GetX();
	float mouseY = Mouse::GetY();
	glm::vec2 normalizedCoords = GetNormalizedDeviceCoords(mouseX, mouseY);
	glm::vec4 clipCoords = glm::vec4(normalizedCoords.x, normalizedCoords.y, -1.0f, 1.0f);
	glm::vec4 eyeCoords = ToEyeCoords(clipCoords);
	glm::vec3 worldRay = ToWorldCoords(eyeCoords);
	return worldRay;
}

glm::vec2 Raycast::GetNormalizedDeviceCoords(float mouseX, float mouseY) {
	float x = (2.0f * mouseX) / Window::GetWidth() - 1.0f;
	float y = (2.0f * mouseY) / Window::GetHeight() - 1.0f;
	return glm::vec2(x, -y);
}

glm::vec4 Raycast::ToEyeCoords(glm::vec4 clipCoords) {
	glm::mat4 invertedProjection = glm::inverse(projectionMatrix);
	glm::vec4 eyeCoords = invertedProjection * clipCoords;
	return glm::vec4(eyeCoords.x, eyeCoords.y, -1.0f, 0.0f);
}

glm::vec3 Raycast::ToWorldCoords(glm::vec4 eyeCoords) {
	glm::mat4 invertedView = glm::inverse(viewMatrix);
	glm::vec4 rayWorld = invertedView * eyeCoords;
	glm::vec3 mouseRay = glm::vec3(rayWorld.x, rayWorld.y, rayWorld.z);
	mouseRay = glm::normalize(mouseRay);
	return mouseRay;
}

glm::vec3 Raycast::GetPointOnRay(float distance) {
	glm::vec3 cameraPos = camera->GetPosition();
	glm::vec3 start = glm::vec3(cameraPos.x, cameraPos.y, cameraPos.z);
	glm::vec3 scaledRay = currentRay * distance;
	return start + scaledRay;
}

glm::vec3 Raycast::BinarySearch(int count, float start, float finish) {
	float half = start + ((finish - start) / 2.0f);
	if (count >= recursionCount) {
		glm::vec3 endPoint = GetPointOnRay(half);
		return endPoint;
	}

	if (IntersectionInRange(start, half)) {
		return BinarySearch(count + 1, start, half);
	} else {
		return BinarySearch(count + 1, half, finish);
	}
}

bool Raycast::IntersectionInRange(float start, float finish) {
	glm::vec3 startPoint = GetPointOnRay(start);
	glm::vec3 endPoint = GetPointOnRay(finish);

	if (!IsUnderGround(startPoint) && IsUnderGround(endPoint)) {
		return true;
	} else {
		return false;
	}
}

bool Raycast::IsUnderGround(glm::vec3 testPoint) {
	if (testPoint.y < hexHeight) {
		return true;
	} else {
		return false;
	}
}
