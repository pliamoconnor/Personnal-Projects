#include "Common.h"

#include <iostream>

int main()
{
	GLFWwindow* window;

	//Initialize lib
	if (!glfwInit())
		return -1;

	if (!glewInit() != GLEW_OK)
		return -1;

	//Create our window
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	char* mem = ReadFile("Assets/Shaders/Default.vertex");
	delete mem;

	//Make the window's context current
	glfwMakeContextCurrent(window);

	EventHandler* eventHandler = new EventHandler();
	Time* timeManager = new Time();

	//Game loop
	while (!glfwWindowShouldClose(window))
	{
		timeManager->NewFrame();

		eventHandler->ProcessEvents();

		//std::cout << "Time elapsed in this program is: " << Time::TimeElapsed() << std::endl;
		//std::cout << "Delta time this frame is equal to: " << Time::DeltaTime() << std::endl;

		//render
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	delete eventHandler;
	delete timeManager;

	glfwTerminate();
	return 0;
}