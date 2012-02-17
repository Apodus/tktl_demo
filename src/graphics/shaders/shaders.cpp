#include "shaders.h"

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;


void Shaders::createShader(const string& shaderName, const string& vertexShader, const string& fragmentShader) {
  shaders[shaderName] = shared_ptr<Shader>(new Shader(vertexShader, fragmentShader));
}

void Shaders::release()
{
	shaders.clear();
}

GLuint Shaders::operator[](const string& program_name) const
{
	auto it = shaders.find(program_name);
	if(it == shaders.end())
	{
		cerr << "WARNING: program " << program_name << " not found!" << endl;
		return -1;
	}
	else
	{
		return it->second->get_program();
	}
}

Shader& Shaders::get_shader(const std::string& program_name)
{
	auto it = shaders.find(program_name);
	if(it == shaders.end())
	{
		cerr << "WARNING: program " << program_name << " not found!" << endl;
		throw std::logic_error("get_shader(" + program_name + ") failed!");
	}
	else
	{
		return *it->second;
	}
}

