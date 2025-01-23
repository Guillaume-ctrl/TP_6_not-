#pragma once
#include "Case.hpp"

class IRS : public Case
{
public:
	IRS();
	void onLanding(Player* landingPlayer);

private:
	int m_tax_value;
};

