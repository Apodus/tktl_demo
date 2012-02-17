
#include <iostream>
#include "graphics/opengl.h"
#include "graphics/window.h"
#include "graphics/texturehandler.h"
#include "graphics/shaders/shaders.h"

#include "misc/timer.h"
#include "statemanager.h"

#include "scene_1.h"

int main(int argc, char** argv) {

	Window window;
	window.createWindow(600, 400);

	// no fullscreen while developing. easier this way.
	// window.toggle_fullscreen();

	OpenGL gl;
	
	TextureHandler::getSingleton().createTexture("test", "data/img.png");
	TextureHandler::getSingleton().deleteTexture("test");

	Shaders shaders;
	shaders.createShader("testShader", "shaders/test.vert", "shaders/test.frag");

	StateManager stateManager;
	stateManager.insertState(new TestScene());
	
	while(stateManager.tick()) {
	  window.swap_buffers();
	}

	std::cout << argv[argc-1] << ": \\o/" << std::endl;
}


