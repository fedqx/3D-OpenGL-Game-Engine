#include "Engine.h"
#define  GLM_FORCE_CTOR_INIT
bool renderit;

short answer;


bool Engine::init()
{
	if (!glfwInit())
	{
		std::cout << "glfwInit error !!!!!!" << std::endl;

		glfwTerminate();
		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(1355, 697, "Frozen Circuit Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		system("pause");
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(window);
	glewInit();

	
	ImGui::CreateContext();


	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();


	ImGui::StyleColorsDark();

	glewExperimental = true;
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window, 1355 / 2.0, 697 / 2.0);

	glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

	
	glViewport(0, 0, 1355, 697);
	glEnable(GL_DEPTH_TEST);
	fpsCamera.mPosition = glm::vec3(0.0f, 3.0f, 10.0f); /// disabled constructor 
	shaderProgram.loadShaders("shaders/basic.vert", "shaders/basic.frag");
	mesh[0].loadOBJ("models/crate.obj");
	mesh[1].loadOBJ("models/k.obj");
	mesh[2].loadOBJ("models/robot.obj");
	mesh[3].loadOBJ("models/floor.obj");

	mesh[0].objtex.loadTexture("textures/crate.jpg", false);
	mesh[1].objtex.loadTexture("textures/k.jpg", false);
	mesh[2].objtex.loadTexture("textures/robot_diffuse.jpg", true);
	mesh[3].objtex.loadTexture("textures/floor.jpg", true);

	mesh[0].modelPos = glm::vec3(-2.5f, 1.0f, 0.0f);
	mesh[1].modelPos = glm::vec3(2.5f, 1.0f, 0.0f);	
	mesh[2].modelPos = glm::vec3(0.0f, 0.0f, -2.0f);
	mesh[3].modelPos = glm::vec3(0.0f, 0.0f, 0.0f);	



	mesh[0].modelScale = glm::vec3(1.0f, 1.0f, 1.0f);	
	mesh[1].modelScale = glm::vec3(0.2f, 0.2f, 0.2f);	
	mesh[2].modelScale = glm::vec3(1.0f, 1.0f, 1.0f);	
	mesh[3].modelScale = glm::vec3(10.0f, 1.0f, 10.0f);
	

	
	return true;
}

void Engine::update(double elapsedTime)
{

	double mouseX, mouseY;

	glfwGetCursorPos(window, &mouseX, &mouseY);


	fpsCamera.rotate((float)(1355 / 2.0 - mouseX) *0.1f, (float)(697 / 2.0 - mouseY) * 0.1f);


	glfwSetCursorPos(window, 1355 / 2.0, 697 / 2.0);


	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		fpsCamera.move(MOVE_SPEED * (float)elapsedTime * fpsCamera.getLook());
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		fpsCamera.move(MOVE_SPEED * (float)elapsedTime * -fpsCamera.getLook());


	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		fpsCamera.move(MOVE_SPEED * (float)elapsedTime * -fpsCamera.getRight());
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		fpsCamera.move(MOVE_SPEED * (float)elapsedTime * fpsCamera.getRight());


	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		fpsCamera.move(MOVE_SPEED * (float)elapsedTime * fpsCamera.getUp());
	else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
		fpsCamera.move(MOVE_SPEED * (float)elapsedTime * -fpsCamera.getUp());
}
bool Engine::render()
{

	// render



	
	glfwPollEvents();
	
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

	
	
	
	if (renderit)
	{
	update(deltaTime);
	}
	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClearColor(0.0f, 0.1f, 0.0f, 1.0f);
	

	
	view = fpsCamera.getViewMatrix();

	
	projection = glm::perspective(glm::radians(fpsCamera.getFOV()), (float)1355 / (float)697, 0.1f, 200.0f);

	
	shaderProgram.use();


	shaderProgram.setUniform("view", view);
	shaderProgram.setUniform("projection", projection);
	

	if (demoobjects)
	{
		
		for (int i = 0; i < 4; i++)
		{
			model = glm::translate(glm::mat4(), mesh[i].modelPos) * glm::scale(glm::mat4(), mesh[i].modelScale);
			shaderProgram.setUniform("model", model);
	
			mesh[i].draw();			
		
		}
	}
	for (int i = 0; i < 12; i++)
	{

		
			model = glm::translate(glm::mat4(), obv[i].modelPos) * glm::scale(glm::mat4(), obv[i].modelScale);
			shaderProgram.setUniform("model", model);

			
			obv[i].draw();
	}
	//model = glm::translate(glm::mat4(), test.modelPos) * glm::scale(glm::mat4(), test.modelScale);
	//shaderProgram.setUniform("model", model);

	//// set the texture before drawing.  Our simple OBJ mesh loader does not do materials yet.
	//test.draw();
	guievents();
	initgui();
		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	

	glfwSwapBuffers(window);
	lastTime = currentTime;
	return false;
}

void Engine::guievents()
{

	
	static int b;
	static int checkt;
	ImGui::InputFloat("x", &obv[b].modelPos.x, 0.0f, 0.0f);
	ImGui::InputFloat("y", &obv[b].modelPos.y, 0.0f, 0.0f);
	ImGui::InputFloat("z", &obv[b].modelPos.z, 0.0f, 0.0f);
	ImGui::InputInt("Object tag", &obv[b].tag);
	ImGui::InputText("Model path", y, IM_ARRAYSIZE(y));
	ImGui::InputText("Texture path", t, IM_ARRAYSIZE(t));
	if (ImGui::Button("add object"))
	{
		if (y == NULL || t == NULL)
		{
			cout << "incorrect model or texure file name !!!" << endl;
			system("pause");
			
		}
		else
		{
			
			obv[b].loadOBJ(y);
			
			obv[b].objtex.loadTexture(t);
			
			obv[b].modelScale = glm::vec3(1.0f, 1.0f, 1.0f);

			
			b++;

		}
			

	}
	ImGui::InputInt("object tag", &checkt);
	ImGui::InputFloat("new x", &newposition.x, 0.0f, 0.0f);
	ImGui::InputFloat("new y", &newposition.y, 0.0f, 0.0f);
	ImGui::InputFloat("new z", &newposition.z, 0.0f, 0.0f);
	if (ImGui::Button("Change OBJ position"))
	{
		for (int i = 0; i < 50; i++)
		{
			if (checkt == obv[i].tag)
			{


				obv[i].modelPos = newposition;

			}
		}
	}
}
bool Engine::changeposition(glm::vec3 newpos, int tag)
{



	return false;
}
short a;
short b;
void Engine::editormode()
{
	renderit = init();

	lastTime = glfwGetTime();
	//render();
	while (!glfwWindowShouldClose(window))
	{

		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;

		render();

		handleevent();
	}
		
		

}

void Engine::playmode()
{
	
	
}


bool Engine::initgui()
{
	ImGui::Checkbox("Demo Models", &demoobjects);


	return 1;
}



Engine::Engine()
{
}


Engine::~Engine()
{
	
	
}



bool Engine::handleevent()
{

	

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
	{
		renderit = true;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		renderit = false;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	
	return true;
}



