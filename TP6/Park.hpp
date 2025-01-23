#pragma once
#include "Case.hpp"

class Park : public Case
{
public:
    Park(const std::string& name);
	void onLanding(Player* landingPlayer);
};

