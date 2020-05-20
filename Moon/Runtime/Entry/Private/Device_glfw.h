#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <vector>

#include "AppI.h"
#include "platform.h"


#if DEVICE_USE_GLFW

namespace moon {

	struct Context
	{

		std::vector<AppI*> appList;

		Context() {
			
		};

		~Context() {
			appList.clear();
		}


		void AddApp(AppI* app)
		{
			appList.push_back(app);
		}


		void processInput(GLFWwindow* window)
		{
			//if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			//	glfwSetWindowShouldClose(window, true);
		}


		void update()
		{
			int len = appList.size();
			for (size_t i = 0; i < len; i++)
			{
				appList[i]->Update();
			}

		}


		void renderFrame()
		{
			int len = appList.size();
			for (size_t i = 0; i < len; i++)
			{
				appList[i]->RenderFrame();
			}
		}


		int run(int argc, const char* const* argv)
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


			GLFWwindow* window = glfwCreateWindow(DEVICE_DEFAULT_WIDTH, DEVICE_DEFAULT_HEIGHT, "Moon", NULL, NULL);
			if (window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				return -1;
			}

			

			glfwMakeContextCurrent(window);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				std::cout << "Failed to initialize GLAD" << std::endl;
				return -1;
			}

			

			while (!glfwWindowShouldClose(window))
			{
				// input
				processInput(window);

				// loop
				update();

				// render
				renderFrame();

				
				glfwSwapBuffers(window);
				glfwPollEvents();
			}

			
			glfwTerminate();
			return 0;
		}
	};

	

static Context s_ctx;

}


#endif // DEVICE_USE_WINDOWS