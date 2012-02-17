
#ifndef H_STATEMANAGER
#define H_STATEMANAGER

#include <vector>
#include "misc/timer.h"

class State;

class StateManager {
  std::vector<State*> states;

public:
  StateManager(): currentState(0), prevTime(Timer::time_now()), currentTime(0) {}
  ~StateManager();

  void insertState(State* state);
  bool tick();
  
  unsigned currentState;
  long long prevTime;
  long long currentTime;
};

#endif
