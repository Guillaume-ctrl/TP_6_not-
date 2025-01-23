#include "Game.hpp"
#include <iostream>

Game* GGame = nullptr;

Game::Game()
{
    this->m_hotel_count = 12;
    this->m_house_count = 32;
    this->m_bank = new Player("Bank");

    /* Handle Player name input */
    std::string inputName = "";
    while (true)
    {
        std::cout << "Enter player name (leave empty to stop): ";
        std::getline(std::cin, inputName);

        if (inputName.empty() && this->canStart())
        {
            std::cout << "Game can now start!" << std::endl;
            break;
        }

        bool bAddedPlayer = this->addPlayer(inputName);
        if (!bAddedPlayer)
        {
            std::cerr << "Failed to add Player: " << inputName << std::endl;
        }
    }

}

Game::~Game()
{
    delete this->m_bank;
}

bool Game::addPlayer(const std::string& playerName)
{
    if(playerName.empty())
        return false;

    if(this->m_player_list.size() >= 8)
        return false;
    
    this->m_player_list.push_back(new Player(playerName));
    
    return true;
}

bool Game::canStart() const
{
    return m_player_list.size() >= 2;
}

void Game::start()
{

}

Player* Game::getBank() const
{
    return this->m_bank;
}
