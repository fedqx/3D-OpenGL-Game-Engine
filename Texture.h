//-----------------------------------------------------------------------------
// Texture2D.h by Steve Jones 
// Copyright (c) 2015-2016 Game Institute. All Rights Reserved.
//
// Simple 2D texture class
// Modified Texture.h by Fatih Melih ÖZGÜN 
//-----------------------------------------------------------------------------
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <glew.h>
#include <string>
using std::string;

class Texture
{
public:
	Texture();
	virtual ~Texture();

	bool loadTexture(const string fileName, bool generateMipMaps = true);
	void bind(GLuint texUnit = 0);
	void unbind(GLuint texUnit = 0);

private:
	//Texture(const Texture& rhs) {}
	//Texture& operator = (const Texture& rhs) {}

	GLuint mTexture;
};
#endif //TEXTURE2D_H
