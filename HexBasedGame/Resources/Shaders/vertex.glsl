#version 330 core
#define MAX_LIGHTS 11

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;
layout (location = 2) in vec3 normal;

out vec2 passTexCoords;
out vec3 surfaceNormal;
out vec3 toLightVector[MAX_LIGHTS];
out vec3 toCameraVector;
out float visibility;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 lightPosition[MAX_LIGHTS];
uniform float fogDensity;
uniform float fogGradient;
uniform vec4 clipPlane;
uniform int numberOfLights;

void main() {
    vec4 worldPosition = model * vec4(position, 1.0);
    gl_ClipDistance[0] = dot(worldPosition, clipPlane);
    vec4 positionRelativeToCamera = view * worldPosition;
    gl_Position = projection * positionRelativeToCamera;
    passTexCoords = texCoords;
    
    surfaceNormal = (model * vec4(normal, 0.0)).xyz;
    for(int i = 0; i < numberOfLights; i++) {
        toLightVector[i] = lightPosition[i] - worldPosition.xyz;
    }
    toCameraVector = (inverse(view) * vec4(0.0, 0.0, 0.0, 1.0)).xyz - worldPosition.xyz;
    
    float distanceFromCamera = length(positionRelativeToCamera);
    visibility = exp(-pow((distanceFromCamera * fogDensity), fogGradient));
    visibility = clamp(visibility, 0.0, 1.0);
}
