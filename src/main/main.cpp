
#include <iostream>
#include "graphics/opengl.h"
#include "graphics/window.h"
#include "graphics/texturehandler.h"

#include "misc/timer.h"

int main(int argc, char** argv) {

	Window window;
	window.createWindow(600, 400);

	OpenGL gl;
	
	TextureHandler::getSingleton().createTexture("test", "data/img.png");
	TextureHandler::getSingleton().deleteTexture("test");

	long long startTime = Timer::time_now();

	while(Timer::time_now() - startTime < 5000) {
		window.swap_buffers();
	}

	std::cout << argv[argc-1] << ": \\o/" << std::endl;
}


