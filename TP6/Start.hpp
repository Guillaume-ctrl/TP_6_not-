#pragma once
#include "Case.hpp"

class Start : public Case
{
public:
	Start();
	void onLanding(Player* landingPlayer);

private:
	int m_passing_reward;
};

