#version 330 core

out vec4 FragColor;

in vec2 passTexCoords;
in vec3 surfaceNormal;
in vec3 toLightVector;
in vec3 toCameraVector;
in float visibility;

uniform sampler2D tex;
uniform vec3 lightColor;
uniform float shineDamper;
uniform float reflectivity;
uniform float isHighlighted;
uniform float isSelected;
uniform vec3 skyColor;

void main() {
    vec3 unitSurfaceNormal = normalize(surfaceNormal);
    vec3 unitToLightVector = normalize(toLightVector);
    
    float nDot1 = dot(unitSurfaceNormal, unitToLightVector);
    float brightness = max(nDot1, 0.4);
    vec3 diffuse = brightness * lightColor;
    
    vec3 unitToCameraVector = normalize(toCameraVector);
    vec3 lightDirection = -unitToLightVector;
    vec3 reflectedLightDirection = reflect(lightDirection, unitSurfaceNormal);
    float specularFactor = dot(reflectedLightDirection, unitToCameraVector);
    specularFactor = max(specularFactor, 0.0);
    float dampedFactor = pow(specularFactor, shineDamper);
    vec3 finalSpecular = dampedFactor * reflectivity * lightColor;
    
    if (isHighlighted == 1.0) {
        FragColor = texture(tex, passTexCoords);
        FragColor = mix(FragColor, vec4(1.0, 1.0, 1.0, 1.0), 0.4);
    } else if (isSelected == 1.0) {
        FragColor = texture(tex, passTexCoords);
    } else {
        FragColor = vec4(diffuse, 1.0) * texture(tex, passTexCoords) + vec4(finalSpecular, 1.0);
        FragColor = mix(vec4(skyColor, 1.0), FragColor, visibility);
    }
}
