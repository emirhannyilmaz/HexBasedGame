#version 460 core

in vec3 position;
out vec3 texCoords;

uniform mat4 view;
uniform mat4 projection;

void main() {
	gl_Position = projection * view * vec4(position, 1.0);
	texCoords = position;
}