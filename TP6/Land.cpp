#include "Land.hpp"

Land::Land(const std::string name, int value) : Case(name)
{
	this->m_owner	= nullptr;
	this->m_value	= value;
	this->m_rent	= 0;
}

void Land::onLanding(Player* landingPlayer)
{
	// Player own the land, do nothing
	if (landingPlayer == this->m_owner)
	{

	}
	// No owner, do something
	else if (this->m_owner == nullptr)
	{

	}
	// Has an owner but landing player isn't him 
	else if(landingPlayer != this->m_owner)
	{

	}
}
