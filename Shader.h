//-----------------------------------------------------------------------------
// Shader.h by Steve Jones 
// Copyright (c) 2015-2016 Game Institute. All Rights Reserved.
//
// GLSL shader manager class
// Modified Shader.h by Fatih Melih ÖZGÜN
//-----------------------------------------------------------------------------
/*Copyright (C) 2018  Mehmet ÖZGÜN
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.*/
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <glew.h>
#include <glm/glm.hpp>
using namespace std;
class Shader
{

public:
	Shader();
	~Shader();
	enum ShaderType
	{
		VERTEX,
		FRAGMENT,
		PROGRAM
	};

	// Only supports vertex and fragment (this series will only have those two)
	bool loadShaders(const char* vsFilename, const char* fsFilename);
	void use();

	GLuint getProgram() const;

	void setUniform(const GLchar* name, const glm::vec2 v);
	void setUniform(const GLchar* name, const glm::vec3 v);
	void setUniform(const GLchar* name, const glm::vec4 v);
	void setUniform(const GLchar* name, const glm::mat4 m);
	void setUniform(const GLchar* name, const GLfloat f);
	void setUniform(const GLchar* name, const GLint v);
	void setUniformSampler(const GLchar* name, const GLint slot);

	// We are going to speed up looking for uniforms by keeping their locations in a map
	GLint getUniformLocation(const GLchar * name);

private:

	string fileToString(const string filename);
	void  checkCompileErrors(GLuint shader, ShaderType type);


	GLuint mHandle;
	std::map<string, GLint> mUniformLocations;
};

