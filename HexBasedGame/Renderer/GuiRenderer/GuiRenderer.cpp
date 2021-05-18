#include "GuiRenderer.h"

void GuiRenderer::Render(std::vector<GuiTexture*>guiTextures, std::vector<GuiButton*> guiButtons) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	guiShader.Start();
	glBindVertexArray(mesh.GetVao()->GetId());
	for (GuiTexture* guiTexture : guiTextures) {
		if (guiTexture->GetIsActive()) {
			guiShader.LoadModelMatrix(guiTexture->GetModelMatrix());
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, guiTexture->GetTexture()->GetId());
			guiShader.LoadIsHighlighted(false);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh.GetVerticesCount());
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
	for (GuiButton* guiButton : guiButtons) {
		if (guiButton->GetIsActive()) {
			guiShader.LoadModelMatrix(guiButton->GetModelMatrix());
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, guiButton->GetTexture()->GetId());
			guiShader.LoadIsHighlighted(guiButton->GetIsHighlighted());
			glDrawArrays(GL_TRIANGLE_STRIP, 0, mesh.GetVerticesCount());
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
	glBindVertexArray(0);
	guiShader.Stop();
	glDisable(GL_BLEND);
}