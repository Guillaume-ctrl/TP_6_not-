#pragma once
#include <vector>
#include <string>
#include "Player.hpp"

/**
 * @brief Global Game object
 */
extern class Game* GGame;

/**
 * @brief Main Game class used to handle current player turn and house/hotel count
 */
class Game
{
public:
	Game();
	~Game();

	bool addPlayer(const std::string& playerName);

	bool canStart() const;
	void start();

	Player* getBank() const;
private:
	Player* m_bank;
	std::vector<Player*> m_player_list = {};
	int m_house_count = 0;
	int m_hotel_count = 0;
};

