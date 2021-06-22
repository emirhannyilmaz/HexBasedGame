#include "SkyboxRenderer.h"

SkyboxRenderer::SkyboxRenderer(Camera* _camera, glm::vec3 _fogColor) {
	camera = _camera;
	fogColor = _fogColor;
	skyboxShader.Start();
	skyboxShader.LoadProjectionMatrix(camera->GetProjectionMatrix());
	skyboxShader.ConnectTextureUnits();
	skyboxShader.Stop();
}

void SkyboxRenderer::Render() {
	skyboxShader.Start();
	skyboxShader.LoadViewMatrix(camera->GetViewMatrix());
	skyboxShader.LoadFogColor(fogColor);
	BindTextures();
	glBindVertexArray(mesh.GetVao()->GetId());
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVerticesCount());
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	skyboxShader.Stop();
}

void SkyboxRenderer::BindTextures() {
	time += Window::GetDeltaTime() * 500.0f;
	time = fmod(time, 24000.0f);
	GLuint texture1;
	GLuint texture2;
	float blendFactor;
	if (time >= 0.0f && time < 5000.0f) {
		texture1 = nightTexture.GetId();
		texture2 = nightTexture.GetId();
		blendFactor = (time - 0.0f) / (5000.0f - 0.0f);
	}
	else if (time >= 5000.0f && time < 8000.0f) {
		texture1 = nightTexture.GetId();
		texture2 = texture.GetId();
		blendFactor = (time - 5000.0f) / (8000.0f - 5000.0f);
	}
	else if (time >= 8000.0f && time < 21000.0f) {
		texture1 = texture.GetId();
		texture2 = texture.GetId();
		blendFactor = (time - 8000.0f) / (21000.0f - 8000.0f);
	}
	else {
		texture1 = texture.GetId();
		texture2 = nightTexture.GetId();
		blendFactor = (time - 21000.0f) / (24000.0f - 21000.0f);
	}

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture2);
	skyboxShader.LoadBlendFactor(blendFactor);
}