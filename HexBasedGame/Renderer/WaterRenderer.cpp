#include "WaterRenderer.h"

const char* WaterRenderer::DUDV_MAP = "Resources/Textures/waterDUDV.png";
const char* WaterRenderer::NORMAL_MAP = "Resources/Textures/normalMap.png";
const float WaterRenderer::WAVE_SPEED = 0.00003f;

WaterRenderer::WaterRenderer(Camera* _camera, WaterFrameBuffers* _fbos) {
    camera = _camera;
    fbos = _fbos;
    waterShader.Start();
    waterShader.ConnectTextureUnits();
    waterShader.LoadProjectionMatrix(camera->GetProjectionMatrix(), camera->GetNear(), camera->GetFar());
    waterShader.Stop();
    waterDudvTexture = new Texture(DUDV_MAP, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, false, false);
    normalMapTexture = new Texture(NORMAL_MAP, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, false, false);
}

void WaterRenderer::Render(std::vector<WaterTile*> waterTiles, Light* light) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    waterShader.Start();
    waterShader.LoadViewMatrix(camera->GetViewMatrix(), camera->GetPosition());
    moveFactor += WaterRenderer::WAVE_SPEED * Window::GetDeltaTime();
    moveFactor = fmod(moveFactor, 1.0f);
    waterShader.LoadMoveFactor(moveFactor);
    waterShader.LoadLight(light);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, fbos->GetReflectionTexture()->GetId());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, fbos->GetRefractionTexture()->GetId());
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, waterDudvTexture->GetId());
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, normalMapTexture->GetId());
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, fbos->GetRefractionDepthTexture()->GetId());
    glBindVertexArray(mesh.GetVao()->GetId());
    for (int i = 0; i < waterTiles.size(); i++) {
        waterShader.LoadModelMatrix(waterTiles.at(i)->GetModelMatrix());
        glDrawArrays(GL_TRIANGLES, 0, mesh.GetVerticesCount());
    }
    glBindVertexArray(0);
    waterShader.Stop();
    glDisable(GL_BLEND);
}
