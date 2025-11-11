#include "Game/Entities/Collectible/AddStep/AddStep.h"

namespace addStep
{
	const Color addStepColor = BEIGE;
	const int stepsAdd = 25;

	AddStep::AddStep(Vector2 pos) : collectible::Collectible(pos, addStepColor), addStep(stepsAdd) {}
	AddStep::~AddStep() {}

	void AddStep::onColEntity(entity::Entity* ent)
	{
		collectible::Collectible::onColEntity(ent);

		player::Player* player = dynamic_cast<player::Player*>(ent);

		if (player)
		{
			player->addStep(addStep);
		}
	}
}