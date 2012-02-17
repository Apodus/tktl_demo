
#ifndef H_STATE_DEMO_KEKKONEN
#define H_STATE_DEMO_KEKKONEN

class State {
public:
  State() {}

  virtual void enterState() = 0;
  virtual void exitState() = 0;
  
  virtual void tick(float dt) = 0;
  virtual bool isActive() = 0;
};

#endif
