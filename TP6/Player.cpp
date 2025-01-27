#include "Player.hpp"

Player::Player(const std::string& name)
{
	this->m_money = 1500;
	this->m_name = name;
	this->m_game_position = 0;
	this->m_inPrison = 0;
	this->m_out = 0;
}

bool Player::payPlayer(Player* otherPlayer, int amount)
{
	if (amount > this->m_money)
	{
		return false;
	}

	m_money -= amount;

	otherPlayer->addMoney(amount);

	return true;
}

void Player::addMoney(int amount)
{
	m_money += amount;
}

void Player::setPosition(unsigned int position)
{
	m_game_position = position;
}

unsigned int Player::getPosition() {
	return m_game_position;
}

std::string Player::getName() const {
	return m_name;
}

unsigned int Player::getMoneyValue() const {
	return m_money;
}

unsigned int Player::setDeductMoney(unsigned int value) {
	if (m_money < 0)
	{
		std::cout << "You do not have any money" << std::endl;
		return m_money;
	}
	m_money = m_money - value;
	return m_money;
}

void Player::addCard(Cards card) {
	m_cartes.push_back(card);
}

void Player::exchangeCard(Player* p, Cards card) {
	
}

void Player::setInPrison(bool p) {
	m_inPrison = p;
}

bool Player::getInPrison() const {
	return m_inPrison;
}

void Player::setOut(bool out) {
	m_out = out;
}

bool Player::getOut() {
	return m_out;
}