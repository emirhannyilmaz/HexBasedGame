#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        vShaderFile.open(vertexShaderPath);
        fShaderFile.open(fragmentShaderPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_READING_FAILED" << std::endl;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    GLint success;
    GLchar infoLog[512];

    vertexId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexId, 1, &vShaderCode, NULL);
    glCompileShader(vertexId);

    glGetShaderiv(vertexId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentId, 1, &fShaderCode, NULL);
    glCompileShader(fragmentId);

    glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    programId = glCreateProgram();
    glAttachShader(programId, vertexId);
    glAttachShader(programId, fragmentId);
    glLinkProgram(programId);

    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

GLint ShaderProgram::GetUniformLocation(const char* uniformName) {
    return glGetUniformLocation(programId, uniformName);
}

void ShaderProgram::LoadMatrix4f(GLint location, glm::mat4 matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::LoadVector3f(GLint location, glm::vec3 vector) {
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void ShaderProgram::LoadVector4f(GLint location, glm::vec4 vector) {
    glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
}

void ShaderProgram::LoadFloat(GLint location, float value) {
    glUniform1f(location, value);
}

void ShaderProgram::LoadBoolean(GLint location, bool value) {
    float toLoad = 0.0f;
    if (value) {
        toLoad = 1.0f;
    }
    glUniform1f(location, toLoad);
}

void ShaderProgram::LoadInt(GLint location, int value) {
    glUniform1i(location, value);
}

void ShaderProgram::Start() {
    glUseProgram(programId);
}

void ShaderProgram::Stop() {
    glUseProgram(0);
}

ShaderProgram::~ShaderProgram() {
    Stop();
    glDetachShader(programId, vertexId);
    glDetachShader(programId, fragmentId);
    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
    glDeleteProgram(programId);
}
