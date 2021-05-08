#include "GuiRenderer.h"

void GuiRenderer::Render(std::vector<GuiTexture*>guiTextures) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	guiShader.Start();
	glBindVertexArray(mesh.GetVao()->GetId());
	for (GuiTexture* guiTexture : guiTextures) {
		guiShader.LoadModelMatrix(guiTexture->GetModelMatrix());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, guiTexture->GetTexture()->GetId());
		glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh.GetVerticesCount());
	}
	glBindVertexArray(0);
	guiShader.Stop();
	glDisable(GL_BLEND);
}