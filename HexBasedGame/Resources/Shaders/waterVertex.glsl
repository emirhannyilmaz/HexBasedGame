#version 330 core

layout (location = 0) in vec3 position;

out vec4 clipSpace;
out vec2 texCoords;
out vec3 toCameraVector;
out vec3 fromLightVector;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 cameraPosition;
uniform vec3 lightPosition;

const float tiling = 10.0;

void main() {
    vec4 worldPosition = model * vec4(position.x, 0.0, position.z, 1.0);
    clipSpace = projection * view * worldPosition;
    gl_Position = clipSpace;
    texCoords = vec2(position.x / 2.0 + 0.5, position.z / 2.0 + 0.5) * tiling;
    toCameraVector = cameraPosition - worldPosition.xyz;
    fromLightVector = worldPosition.xyz - lightPosition;
}
