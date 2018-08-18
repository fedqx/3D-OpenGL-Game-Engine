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



