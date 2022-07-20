#include <iostream>
#ifdef NANOVG_GLEW
#  include <GL/glew.h>
#endif
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "nanovg-master/src/nanovg.h"
#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg-master/src/nanovg_gl.h"
#include "nanovg-master/example/perf.h"
#include <vector>
#include "Vector3.h"

void errorcb(int error, const char* desc)
{
	printf("GLFW error %d: %s\n", error, desc);
}

int blowup = 0;
int screenshot = 0;
int premult = 0;

static void key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	NVG_NOTUSED(scancode);
	NVG_NOTUSED(mods);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		blowup = !blowup;
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		screenshot = 1;
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		premult = !premult;
}

int main()
{
	GLFWwindow* window;
	NVGcontext* vg = NULL;
	PerfGraph fps;
	double prevt = 0;

	if (!glfwInit()) {
		printf("Failed to init GLFW.");
		return -1;
	}

	initGraph(&fps, GRAPH_RENDER_FPS, "Frame Time");

	glfwSetErrorCallback(errorcb);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#ifdef DEMO_MSAA
	glfwWindowHint(GLFW_SAMPLES, 4);
#endif

	window = glfwCreateWindow(1000, 600, "NanoVG", NULL, NULL);
//	window = glfwCreateWindow(1000, 600, "NanoVG", glfwGetPrimaryMonitor(), NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key);

	glfwMakeContextCurrent(window);
#ifdef NANOVG_GLEW
    if(glewInit() != GLEW_OK) {
		printf("Could not init glew.\n");
		return -1;
	}
#endif

#ifdef DEMO_MSAA
	vg = nvgCreateGL2(NVG_STENCIL_STROKES | NVG_DEBUG);
#else
	vg = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
#endif
	if (vg == NULL) {
		printf("Could not init nanovg.\n");
		return -1;
	}

	glfwSwapInterval(0);

	glfwSetTime(0);
	prevt = glfwGetTime();

	Vector3 *p1 = new Vector3(100, 100, 0);
	Vector3 *p2 = new Vector3(200, 100, 0);
	Vector3 *p3 = new Vector3(100, 200, 0);

	std::vector<Vector3 *> points = {p1, p2, p3};
	Vector3 *mouse = new Vector3();

	while (!glfwWindowShouldClose(window))
	{
		double mx, my, t, dt;
		int winWidth, winHeight;
		int fbWidth, fbHeight;
		float pxRatio;

		t = glfwGetTime();
		dt = t - prevt;
		prevt = t;
		updateGraph(&fps, dt);

		glfwGetCursorPos(window, &mx, &my);
		mouse->x = mx;
		mouse->y = my;
		glfwGetWindowSize(window, &winWidth, &winHeight);
		glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

		// Calculate pixel ratio for hi-dpi devices.
		pxRatio = (float)fbWidth / (float)winWidth;

		// Update and render
		glViewport(0, 0, fbWidth, fbHeight);
		if (premult)
			glClearColor(0,0,0,0);
		else
			glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

		nvgBeginFrame(vg, winWidth, winHeight, pxRatio);

		renderGraph(vg, 5,5, &fps);

		points[0]->x = mouse->x; points[0]->y = mouse->y;
		points[1]->x = mouse->x + 100; points[1]->y = mouse->y;
		points[2]->x = mouse->x; points[2]->y = mouse->y + 100;

		nvgBeginPath(vg);
		
		nvgMoveTo(vg, points[0]->x, points[0]->y);
		nvgLineTo(vg, points[1]->x, points[1]->y);
		nvgLineTo(vg, points[2]->x, points[2]->y);


		nvgFill(vg);

		nvgEndFrame(vg);

		if (screenshot) {
			screenshot = 0;
			std::cout << "screenshot taken" << std::endl;
		}
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	nvgDeleteGL2(vg);

	glfwTerminate();
	return 0;
}