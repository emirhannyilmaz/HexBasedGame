#include "TextRenderer.h"

TextRenderer::TextRenderer(std::map<char, Character*> _characters) {
	characters = _characters;

	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float) Window::GetWidth(), 0.0f, (float) Window::GetHeight());

	shader.Start();
	shader.LoadProjectionMatrix(projectionMatrix);
	shader.Stop();
}

void TextRenderer::Render(std::vector<Text*> texts) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	shader.Start();
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(mesh.GetVao()->GetId());
	for (int i = 0; i < texts.size(); i++) {
		std::string text = texts.at(i)->GetText();
		float x = texts.at(i)->GetPosition().x;
		float y = texts.at(i)->GetPosition().y;
		float textWidth = 0.0f;
		if (texts.at(i)->GetIsActive()) {
			shader.LoadTextColor(texts.at(i)->GetColor());
			std::string::const_iterator c;
			if (texts.at(i)->GetIsCentered()) {
				for (c = text.begin(); c != text.end(); c++) {
					Character* ch = characters[*c];
					textWidth += ch->GetSize().x * texts.at(i)->GetScale().x;
				}
				x = texts.at(i)->GetPosition().x - (textWidth / 2.0f);
			}
			for (c = text.begin(); c != text.end(); c++) {
				Character* ch = characters[*c];

				float xpos = x + ch->GetBearing().x * texts.at(i)->GetScale().x;
				float ypos = y - (ch->GetSize().y - ch->GetBearing().y) * texts.at(i)->GetScale().y;

				float w = ch->GetSize().x * texts.at(i)->GetScale().x;
				float h = ch->GetSize().y * texts.at(i)->GetScale().y;

				float vertices[6][4] = {
					{xpos, ypos + h, 0.0f, 0.0f},
					{xpos, ypos, 0.0f, 1.0f},
					{xpos + w, ypos, 1.0f, 1.0f},

					{xpos, ypos + h, 0.0f, 0.0f},
					{xpos + w, ypos, 1.0f, 1.0f},
					{xpos + w, ypos + h, 1.0f, 0.0f}
				};

				glBindTexture(GL_TEXTURE_2D, ch->GetTexture()->GetId());
				glBindBuffer(GL_ARRAY_BUFFER, mesh.GetVbo1()->GetId());
				glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
				glBindBuffer(GL_ARRAY_BUFFER, 0);
				glDrawArrays(GL_TRIANGLES, 0, 6);
				glBindTexture(GL_TEXTURE_2D, 0);

				x += (ch->GetAdvance() >> 6) * texts.at(i)->GetScale().x;
			}
		}
	}
	glBindVertexArray(0);
	shader.Stop();
	glDisable(GL_BLEND);
}

TextRenderer::~TextRenderer() {
	for (auto c : characters) {
		delete c.second;
	}
}