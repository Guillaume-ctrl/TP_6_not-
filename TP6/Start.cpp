#include "Start.hpp"

Start::Start() : Case("Depart")
{
	this->m_passing_reward = 200;
}

void Start::onLanding(Player* landingPlayer)
{
	landingPlayer->addMoney(this->m_passing_reward);
}
