#version 330 core

out vec4 FragColor;

in vec4 clipSpace;
in vec2 texCoords;
in vec3 toCameraVector;
in vec3 fromLightVector[4];
in float visibility;

uniform sampler2D reflectionTexture;
uniform sampler2D refractionTexture;
uniform sampler2D dudvMap;
uniform sampler2D normalMap;
uniform sampler2D depthMap;
uniform float moveFactor;
uniform vec3 lightColor[4];
uniform vec3 attenuation[4];
uniform float near;
uniform float far;
uniform vec3 skyColor;

const float waveStrength = 0.02;
const float refractivity = 5.0;
const float shineDamper = 20.0;
const float reflectivity = 0.3;

void main() {
    vec2 ndc = (clipSpace.xy / clipSpace.w) / 2.0 + 0.5;
    vec2 reflectionTexCoords = vec2(ndc.x, -ndc.y);
    vec2 refractionTexCoords = vec2(ndc.x, ndc.y);

    float depth = texture(depthMap, refractionTexCoords).r;
    float floorDistance = 2.0 * near * far / (far + near - (2.0 * depth - 1.0) * (far - near));

    depth = gl_FragCoord.z;
    float waterDistance = 2.0 * near * far / (far + near - (2.0 * depth - 1.0) * (far - near));
    float waterDepth = floorDistance - waterDistance;
    
    vec2 distortedTexCoords = texture(dudvMap, vec2(texCoords.x + moveFactor, texCoords.y)).rg * 0.1;
    distortedTexCoords = texCoords + vec2(distortedTexCoords.x, distortedTexCoords.y + moveFactor);
    vec2 totalDistortion = (texture(dudvMap, distortedTexCoords).rg * 2.0 - 1.0) * waveStrength * clamp(waterDepth / 20.0, 0.0, 1.0);
    
    reflectionTexCoords += totalDistortion;
    reflectionTexCoords.x = clamp(reflectionTexCoords.x, 0.001, 0.999);
    reflectionTexCoords.y = clamp(reflectionTexCoords.y, -0.999, -0.001);
    
    refractionTexCoords += totalDistortion;
    refractionTexCoords = clamp(refractionTexCoords, 0.001, 0.999);
    
    vec4 reflectionColor = texture(reflectionTexture, reflectionTexCoords);
    vec4 refractionColor = texture(refractionTexture, refractionTexCoords);
    
    vec4 normalMapColor = texture(normalMap, distortedTexCoords);
    vec3 normal = vec3(normalMapColor.r * 2.0 - 1.0, normalMapColor.b, normalMapColor.g * 2.0 - 1.0);
    normal = normalize(normal);
    
    vec3 normToCameraVector = normalize(toCameraVector);
    float refractiveFactor = dot(normToCameraVector, normal);
    refractiveFactor = pow(refractiveFactor, refractivity);
    refractiveFactor = clamp(refractiveFactor, 0.0, 1.0);
    
    vec3 totalSpecular = vec3(0.0);

    for(int i = 0; i < 4; i++) {
        float distance = length(fromLightVector[i]);
        float attFactor = attenuation[i].x + (attenuation[i].y * distance) + (attenuation[i].z * distance * distance);
        vec3 reflectedLight = reflect(normalize(fromLightVector[i]), normal);
        float specular = max(dot(reflectedLight, normToCameraVector), 0.0);
        specular = pow(specular, shineDamper);
        totalSpecular = totalSpecular + ((lightColor[i] * specular * reflectivity) / attFactor) * clamp(waterDepth / 5.0, 0.0, 1.0);
    }

    FragColor = mix(reflectionColor, refractionColor, refractiveFactor);
    FragColor = mix(FragColor, vec4(0.0, 0.3, 0.5, 1.0), 0.3) + vec4(totalSpecular, 0.0);
    FragColor = mix(vec4(skyColor, 1.0), FragColor, visibility);
    FragColor.a = clamp(waterDepth / 5.0, 0.0, 1.0);
}
