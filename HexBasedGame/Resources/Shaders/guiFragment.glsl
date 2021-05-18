#version 330 core

out vec4 FragColor;

in vec2 texCoords;

uniform sampler2D tex;
uniform float isHighlighted;

void main() {
	if (isHighlighted == 1.0) {
		FragColor = mix(texture(tex, texCoords), vec4(1.0, 1.0, 1.0, 1.0), 0.3);
	} else {
		FragColor = texture(tex, texCoords);
	}
}