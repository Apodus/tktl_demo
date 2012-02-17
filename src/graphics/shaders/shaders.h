#ifndef SHADERS_H
#define SHADERS_H

#include "opengl.h"

#include <map>
#include <string>
#include <memory>

#include "shader.h"

class Shaders
{
public:
  void release();
  void createShader(const std::string& shaderName, const std::string& vertexShader, const std::string& fragmentShader);
  
  GLuint operator[](const std::string& program_name) const;
  Shader& get_shader(const std::string& program_name);
  
private:
  std::map<std::string, std::shared_ptr<Shader> > shaders;
};

#endif

