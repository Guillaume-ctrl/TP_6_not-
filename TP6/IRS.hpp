#pragma once
#include "Case.hpp"

class IRS : public Case
{
public:
	IRS(const std::string name, int tax_value);
	void onLanding(Player* landingPlayer);

private:
	int m_tax_value;
};

