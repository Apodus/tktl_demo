
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

	// TODO: Wrap this up.
	std::vector<State*> states;
	states.push_back(new TestScene());
	unsigned currentState = 0;

	long long prevTime = Timer::time_now();
	long long currentTime;

	while(currentState < states.size()) {
	  currentTime = Timer::time_now();
	  states[currentState]->tick( (currentTime - prevTime) / 1000.f );
	  window.swap_buffers();
	  if(!states[currentState]->isActive())
		++currentState;
	}

	std::cout << argv[argc-1] << ": \\o/" << std::endl;
}


