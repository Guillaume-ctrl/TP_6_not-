#pragma once
#include <string>
#include "Case.hpp"

class Player
{
public:
	Player(const std::string& name);

	bool payPlayer(Player* otherPlayer, int amount);

	void addMoney(int amount);

private:
	Case* m_current_case;
	int m_money;
	std::string m_name;
};

