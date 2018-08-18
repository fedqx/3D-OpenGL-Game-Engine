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
#include "Sound.h"
#include "Character.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
using namespace std;

class Engine
{
public:
	FPSCamera fpsCamera;
	Shader shaderProgram;
	EngineObject mesh[4];
	
	glm::mat4 model, view, projection;
	int windowh = 697;
	int windoww = 1355;
	char  t[128];
	char  y[128];
	GLFWwindow * window;
	glm::vec3 newposition;
	
	//vector<EngineObject> obv;
	vector<EngineObject> testvec;
	EngineObject obv[12];
	bool editoron = true;
	bool eisrunning;
	double lastTime;
	Character player;
	double currentTime;
	double deltaTime;
	//bool test;
	bool demoobjects;
	const float MOVE_SPEED = 10.0; // units per second
	Engine();
	~Engine();
	void update(double elapsedTime);
	bool init();
	bool render();
	bool handleevent();
	void playmode();
	void editormode();
	bool initgui();
	void guievents();
	bool changeposition(glm::vec3 newpos, int tag);
};



