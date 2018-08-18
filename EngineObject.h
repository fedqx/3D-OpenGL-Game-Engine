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
#define  GLM_FORCE_CTOR_INIT
#include "Include.h"
#include "Texture.h"
#include <vector>
#include <string>

#include <glew.h>	// Important - this header must come before glfw3 header
#include <glm/glm.hpp>


struct Vertex
{
	glm::vec3 position;

	glm::vec2 texCoords;
};

class EngineObject 
{
public:
	

	
	glm::vec3 modelScale;
	glm::vec3 modelPos;
	int tag;	
	bool inited;

	Texture objtex;

	bool loadOBJ(const std::string filename);
	void draw();
	
		glm::mat4 model, view, projection;

	void initBuffers();

	bool mLoaded;
	std::vector<Vertex> mVertices;
	GLuint mVBO, mVAO;
	EngineObject();
	~EngineObject();
	
};

