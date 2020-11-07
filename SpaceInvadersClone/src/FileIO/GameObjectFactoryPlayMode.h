#pragma once
#include <vector>
#include "../GameObjects/GameObject.h"
#include "GameObjectBluprint.h"

class GameObjectFactoryPlayMode
{
public:
	void buildGameObject(GameObjectBluprint& bp, std::vector<GameObject>& gameObjects);
};