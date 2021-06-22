#include "ObjLoader.h"

void ObjLoader::LoadObj(const char* filePath, std::vector<glm::vec3>& outVertices, std::vector<glm::vec2>& outTexCoords, std::vector<glm::vec3>& outNormals, std::vector<GLuint>& outIndices, std::vector<Collider>& outColliders) {
	std::vector<unsigned int> vertexIndices, texCoordIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec2> tempTexCoords;
	std::vector<glm::vec3> tempNormals;

	FILE* file = fopen(filePath, "r");
	if (file == NULL) {
		std::cout << "ERROR::OBJLOADER::FILE_READING_FAILED" << std::endl;
	}

	while (1) {
		char lineHeader[128];

		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break;
		}

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
			if (outColliders.size() != 0) {
				outColliders.back().AddVertex(vertex);
			}
			else {
				tempVertices.push_back(vertex);
			}
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 texCoord;
			fscanf(file, "%f %f", &texCoord.x, &texCoord.y);
			tempTexCoords.push_back(texCoord);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f", &normal.x, &normal.y, &normal.z);
			tempNormals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			unsigned int vertexIndex[3];
			unsigned int texCoordIndex[3];
			unsigned int normalIndex[3];
			fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &texCoordIndex[0], &normalIndex[0], &vertexIndex[1], &texCoordIndex[1], &normalIndex[1], &vertexIndex[2], &texCoordIndex[2], &normalIndex[2]);
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			texCoordIndices.push_back(texCoordIndex[0]);
			texCoordIndices.push_back(texCoordIndex[1]);
			texCoordIndices.push_back(texCoordIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
		else if (strcmp(lineHeader, "o") == 0) {
			char colliderName[512];
			fscanf(file, "%s", &colliderName[0]);
			std::string strColliderName(&colliderName[0]);
			if (strColliderName.find("Collider") != std::string::npos) {
				outColliders.push_back(Collider());
			}
		}
	}

	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = tempVertices[vertexIndex - 1];
		outVertices.push_back(vertex);
		outIndices.push_back(i);
	}

	for (unsigned int i = 0; i < texCoordIndices.size(); i++) {
		unsigned int texCoordIndex = texCoordIndices[i];
		glm::vec2 texCoord = tempTexCoords[texCoordIndex - 1];
		outTexCoords.push_back(texCoord);
	}

	for (unsigned int i = 0; i < normalIndices.size(); i++) {
		unsigned int normalIndex = normalIndices[i];
		glm::vec3 normal = tempNormals[normalIndex - 1];
		outNormals.push_back(normal);
	}
}

void ObjLoader::LoadObj(const char* filePath, std::vector<glm::vec3>& outVertices, std::vector<glm::vec2>& outTexCoords, std::vector<glm::vec3>& outNormals, std::vector<GLuint>& outIndices, std::vector<Light>& outLights) {
	std::vector<unsigned int> vertexIndices, texCoordIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec2> tempTexCoords;
	std::vector<glm::vec3> tempNormals;

	FILE* file = fopen(filePath, "r");
	if (file == NULL) {
		std::cout << "ERROR::OBJLOADER::FILE_READING_FAILED" << std::endl;
	}

	while (1) {
		char lineHeader[128];

		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break;
		}

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
			tempVertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 texCoord;
			fscanf(file, "%f %f", &texCoord.x, &texCoord.y);
			tempTexCoords.push_back(texCoord);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f", &normal.x, &normal.y, &normal.z);
			tempNormals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			unsigned int vertexIndex[3];
			unsigned int texCoordIndex[3];
			unsigned int normalIndex[3];
			fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &texCoordIndex[0], &normalIndex[0], &vertexIndex[1], &texCoordIndex[1], &normalIndex[1], &vertexIndex[2], &texCoordIndex[2], &normalIndex[2]);
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			texCoordIndices.push_back(texCoordIndex[0]);
			texCoordIndices.push_back(texCoordIndex[1]);
			texCoordIndices.push_back(texCoordIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
		else if (strcmp(lineHeader, "l") == 0) {
			glm::vec3 position;
			glm::vec3 color;
			glm::vec3 attenutation;
			fscanf(file, "%f %f %f %f %f %f %f %f %f", &position.x, &position.y, &position.z, &color.x, &color.y, &color.z, &attenutation.x, &attenutation.y, &attenutation.z);
			outLights.push_back(Light(position, color, attenutation));
		}
	}

	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = tempVertices[vertexIndex - 1];
		outVertices.push_back(vertex);
		outIndices.push_back(i);
	}

	for (unsigned int i = 0; i < texCoordIndices.size(); i++) {
		unsigned int texCoordIndex = texCoordIndices[i];
		glm::vec2 texCoord = tempTexCoords[texCoordIndex - 1];
		outTexCoords.push_back(texCoord);
	}

	for (unsigned int i = 0; i < normalIndices.size(); i++) {
		unsigned int normalIndex = normalIndices[i];
		glm::vec3 normal = tempNormals[normalIndex - 1];
		outNormals.push_back(normal);
	}
}

void ObjLoader::LoadObj(const char* filePath, std::vector<glm::vec3>& outVertices, std::vector<glm::vec2>& outTexCoords, std::vector<glm::vec3>& outNormals, std::vector<GLuint>& outIndices) {
	std::vector<unsigned int> vertexIndices, texCoordIndices, normalIndices;
	std::vector<glm::vec3> tempVertices;
	std::vector<glm::vec2> tempTexCoords;
	std::vector<glm::vec3> tempNormals;

	FILE* file = fopen(filePath, "r");
	if (file == NULL) {
		std::cout << "ERROR::OBJLOADER::FILE_READING_FAILED" << std::endl;
	}

	while (1) {
		char lineHeader[128];

		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break;
		}

		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
			tempVertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 texCoord;
			fscanf(file, "%f %f", &texCoord.x, &texCoord.y);
			tempTexCoords.push_back(texCoord);
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f", &normal.x, &normal.y, &normal.z);
			tempNormals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			unsigned int vertexIndex[3];
			unsigned int texCoordIndex[3];
			unsigned int normalIndex[3];
			fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &texCoordIndex[0], &normalIndex[0], &vertexIndex[1], &texCoordIndex[1], &normalIndex[1], &vertexIndex[2], &texCoordIndex[2], &normalIndex[2]);
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			texCoordIndices.push_back(texCoordIndex[0]);
			texCoordIndices.push_back(texCoordIndex[1]);
			texCoordIndices.push_back(texCoordIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}

	for (unsigned int i = 0; i < vertexIndices.size(); i++) {
		unsigned int vertexIndex = vertexIndices[i];
		glm::vec3 vertex = tempVertices[vertexIndex - 1];
		outVertices.push_back(vertex);
		outIndices.push_back(i);
	}

	for (unsigned int i = 0; i < texCoordIndices.size(); i++) {
		unsigned int texCoordIndex = texCoordIndices[i];
		glm::vec2 texCoord = tempTexCoords[texCoordIndex - 1];
		outTexCoords.push_back(texCoord);
	}

	for (unsigned int i = 0; i < normalIndices.size(); i++) {
		unsigned int normalIndex = normalIndices[i];
		glm::vec3 normal = tempNormals[normalIndex - 1];
		outNormals.push_back(normal);
	}
}