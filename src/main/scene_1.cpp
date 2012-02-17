
#include "scene_1.h"
#include <iostream>

TestScene::TestScene() : activeTime(0)
{
}

void TestScene::enterState()
{
  activeTime = 0;
}

void TestScene::exitState()
{
}

void TestScene::tick(float dt)
{
  std::cout << dt << std::endl;
  std::cout << "tick" << std::endl;
  activeTime += dt;
}

bool TestScene::isActive()
{
  return activeTime < 5.0f;
}
