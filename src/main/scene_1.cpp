
#include "scene_1.h"
#include <iostream>

#include "graphics/opengl.h"

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

  glClearColor(activeTime * 0.2f, 0.2f, 1.0f - activeTime * 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

bool TestScene::isActive()
{
  return activeTime < 5.0f;
}
