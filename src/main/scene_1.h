
#ifndef H_SCENE_1_
#define H_SCENE_1_

#include "state.h"

class TestScene : public State {
public:
  TestScene();
  void enterState();
  void exitState();
  
  void tick(float dt);
  bool isActive();
private:
  float activeTime;
};

#endif
