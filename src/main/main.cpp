
#include <iostream>
#include "graphics/opengl.h"
#include "graphics/window.h"

int main(int argc, char** argv) {

	Window window;
	window.createWindow(600, 400);

	OpenGL gl;

	while(1) {
		window.swap_buffers();
	}

	std::cout << argv[argc-1] << ": \\o/" << std::endl;
}


