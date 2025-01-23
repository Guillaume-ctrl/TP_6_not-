#include "IRS.hpp"
#include "Game.hpp"

IRS::IRS() : Case("IRS")
{
	this->m_tax_value = 200;
}

void IRS::onLanding(Player* landingPlayer)
{
	landingPlayer->payPlayer(GGame->getBank(), this->m_tax_value);
}
