
#include "scene_1.h"

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
  activeTime += dt;
}

bool TestScene::isActive()
{
  return activeTime > 5.0f;
}
