#include <GLFW/glfw3.h>
#include <iostream>

#include "AppI.h"
#include "platform.h"


#if DEVICE_USE_GLFW

namespace moon {

	struct Context
	{

		AppI* appI;

		Context() {
			appI = new AppI();
		};

		~Context() {
			if (appI) {
				delete appI;
				appI = nullptr;
			}
		}


		void processInput(GLFWwindow* window)
		{
			//if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			//	glfwSetWindowShouldClose(window, true);
		}


		void update()
		{
			appI->Update();
		}


		void renderFrame()
		{
			appI->RenderFrame();
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

int main(int argc, const char* const* argv)
{
	return moon::s_ctx.run(argc, argv);
}

#endif // DEVICE_USE_WINDOWS