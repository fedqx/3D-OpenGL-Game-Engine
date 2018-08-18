//-----------------------------------------------------------------------------
// Texture2D.h by Steve Jones 
// Copyright (c) 2015-2016 Game Institute. All Rights Reserved.
//
// Simple 2D texture class
// Modified Texture.h by Fatih Melih ÖZGÜN 
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
