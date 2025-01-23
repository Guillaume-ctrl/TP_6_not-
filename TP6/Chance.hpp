#pragma once
#include "Case.hpp"

class Chance : public Case
{
public:
	Chance(const std::string& name);
	void onLanding(Player* landingPlayer);

private:
};

