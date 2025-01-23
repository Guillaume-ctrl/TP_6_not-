#pragma once
#include <string>
class Player
{
public:
	Player(const std::string& name);

	bool payPlayer(Player* otherPlayer, int amount);

	void addMoney(int amount);

private:
	int m_money;
	std::string m_name;
};

