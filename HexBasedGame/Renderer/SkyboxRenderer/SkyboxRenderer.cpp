#include "SkyboxRenderer.h"

SkyboxRenderer::SkyboxRenderer(Camera* _camera) {
	camera = _camera;
	skyboxShader.Start();
	skyboxShader.LoadProjectionMatrix(camera->GetProjectionMatrix());
	skyboxShader.Stop();
}

void SkyboxRenderer::Render() {
	skyboxShader.Start();
	skyboxShader.LoadViewMatrix(camera->GetViewMatrix());
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture.GetId());
	glBindVertexArray(mesh.GetVao()->GetId());
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVerticesCount());
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	skyboxShader.Stop();
}