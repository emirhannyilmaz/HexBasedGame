#version 460 core

in vec3 texCoords;
out vec4 FragColor;

uniform vec3 fogColor;
uniform samplerCube cubeMap;
uniform samplerCube cubeMap2;
uniform float blendFactor;

const float lowerLimit = -30.0;
const float upperLimit = -10.0;

void main() {
	vec4 texture1 = texture(cubeMap, texCoords);
	vec4 texture2 = texture(cubeMap2, texCoords);

	vec4 finalColor = mix(texture1, texture2, blendFactor);
	
	float factor = (texCoords.y - lowerLimit) / (upperLimit - lowerLimit);
	factor = clamp(factor, 0.0, 1.0);
	FragColor = mix(vec4(fogColor, 1.0), finalColor, factor);
}