#version 330 core
#define MAX_LIGHTS 16

out vec4 FragColor;

in vec2 passTexCoords;
in vec3 surfaceNormal;
in vec3 toLightVector[MAX_LIGHTS];
in vec3 toCameraVector;
in float visibility;

uniform sampler2D tex;
uniform vec3 lightColor[MAX_LIGHTS];
uniform vec3 attenuation[MAX_LIGHTS];
uniform float shineDamper;
uniform float reflectivity;
uniform float isHighlighted;
uniform float isSelected;
uniform vec3 skyColor;
uniform int numberOfLights;

void main() {
    vec3 unitSurfaceNormal = normalize(surfaceNormal);
    vec3 unitToCameraVector = normalize(toCameraVector);

    vec3 totalDiffuse = vec3(0.0);
    vec3 totalSpecular = vec3(0.0);
    
    for(int i = 0; i < numberOfLights; i++) {
        float distance = length(toLightVector[i]);
        float attFactor = attenuation[i].x + (attenuation[i].y * distance) + (attenuation[i].z * distance * distance);
        vec3 unitToLightVector = normalize(toLightVector[i]);
        float nDot1 = dot(unitSurfaceNormal, unitToLightVector);
        float brightness = max(nDot1, 0.0);
        vec3 lightDirection = -unitToLightVector;
        vec3 reflectedLightDirection = reflect(lightDirection, unitSurfaceNormal);
        float specularFactor = dot(reflectedLightDirection, unitToCameraVector);
        specularFactor = max(specularFactor, 0.0);
        float dampedFactor = pow(specularFactor, shineDamper);
        totalDiffuse = totalDiffuse + (brightness * lightColor[i]) / attFactor;
        totalSpecular = totalSpecular + (dampedFactor * reflectivity * lightColor[i]) / attFactor;
    }

    totalDiffuse = max(totalDiffuse, 0.2);
    
    if (isHighlighted == 1.0) {
        FragColor = texture(tex, passTexCoords);
        FragColor = mix(FragColor, vec4(1.0, 1.0, 1.0, 1.0), 0.4);
    } else if (isSelected == 1.0) {
        FragColor = texture(tex, passTexCoords);
    } else {
        FragColor = vec4(totalDiffuse, 1.0) * texture(tex, passTexCoords) + vec4(totalSpecular, 1.0);
        FragColor = mix(vec4(skyColor, 1.0), FragColor, visibility);
    }
}
