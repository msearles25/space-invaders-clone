#pragma once
#include "../FileIO/GameObjectSharer.h"
#include "../GameObjects/PlayerUpdateComponent.h"

class PhysicsEnginePlayMode
{
private:
	std::shared_ptr<PlayerUpdateComponent> m_PUC;

	GameObject* m_Player;
	bool m_InvaderHitWallThisFrame{ false };
	bool m_InvaderHitWallPreviousFrame{ false };
	bool m_NeedToDropDownAndReverse{ false };
	bool m_CompletedDropDownAndReverse{ false };

	void detectInvaderCollisons(
		std::vector<GameObject>& objects, 
		const std::vector<int>& bulletPosition);
	
	void detectPlayerCollisionsAndInvaderDirecton(
		std::vector<GameObject>& objects,
		const std::vector<int>& bulletPositions);

	void handleInvaderDirection();
public:
	void initialize(GameObjectSharer& gos);
	void detectCollisions(
		std::vector<GameObject>& objects,
		const std::vector<int>& bulletPositions);
};