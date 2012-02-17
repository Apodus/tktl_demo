
#include "statemanager.h"
#include "state.h"

void StateManager::insertState(State* state) {
  states.push_back(state);
}

StateManager::~StateManager() {
  for(unsigned i=0; i<states.size(); ++i)
	delete states[i];
  states.clear();
}

bool StateManager::tick() {
  currentTime = Timer::time_now();
  states[currentState]->tick( (currentTime - prevTime) / 1000.f );
  prevTime = currentTime;

  if(!states[currentState]->isActive()) {
	states[currentState]->exitState();
	if(++currentState < states.size())
	  states[++currentState]->enterState();
  }
  
  return currentState < states.size();
}
