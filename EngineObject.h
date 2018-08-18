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

