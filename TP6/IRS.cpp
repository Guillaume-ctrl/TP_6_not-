#include "IRS.hpp"
#include "Game.hpp"

IRS::IRS(const std::string name, int tax_value) : Case(name)
{
	this->m_tax_value = tax_value;
}

void IRS::onLanding(Player* landingPlayer)
{
	landingPlayer->payPlayer(GGame->getBank(), this->m_tax_value);
}
