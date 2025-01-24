#include "Player.hpp"

Player::Player(const std::string& name)
{
	this->m_money = 0;
	this->m_name = name;
	this->m_current_case = nullptr;
}

bool Player::payPlayer(Player* otherPlayer, int amount)
{
	if (amount > this->m_money)
	{
		return false;
	}

	this->m_money -= amount;

	otherPlayer->addMoney(amount);

	return true;
}

void Player::addMoney(int amount)
{
	this->m_money += amount;
}
