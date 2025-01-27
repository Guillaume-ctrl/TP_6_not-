#pragma once
#include <vector>
#include <string>
#include "Player.hpp"
#include "Case.hpp"

/**
 * @brief Global Game object
 *
 * This serves as the main entry point for the game, allowing global access
 * to the Game instance.
 */
extern class Game* GGame;

/**
 * @class Game
 * @brief Main Game class used to manage the gameplay loop, players, and game state.
 *
 * The Game class is responsible for handling the current player turn, managing
 * houses and hotels, and coordinating player actions. It also includes methods
 * to start and play the game, check player status, and display information about
 * cases on the board.
 */
class Game {
public:
    /**
     * @brief Constructor for the Game class.
     *
     * Initializes the game with default values, including setting up the bank
     * and player list.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     *
     * Cleans up resources, including deleting dynamically allocated players.
     */
    ~Game();

    /**
     * @brief Adds a player to the game.
     *
     * @param playerName The name of the player to add.
     * @return True if the player was added successfully, false otherwise.
     */
    bool addPlayer(const std::string& playerName);

    /**
     * @brief Checks if the game is ready to start.
     *
     * A game can start if there are enough players added.
     *
     * @return True if the game can start, false otherwise.
     */
    bool canStart() const;

    /**
     * @brief Starts the game.
     *
     * This method initializes the game state and prepares for the first turn.
     */
    void start();

    /**
     * @brief Executes the main game loop for the current player's turn.
     *
     * Handles the player's actions, dice rolls, and case interactions.
     */
    void play();

    /**
     * @brief Checks the status of the current player.
     *
     * Determines whether the player is still in the game or needs to be removed.
     */
    void checkPlayer();

    /**
     * @brief Checks if the game has ended.
     *
     * The game ends when only one player remains.
     *
     * @return True if the game has ended, false otherwise.
     */
    bool hasEnded();

    /**
     * @brief Displays information about a specific case on the board.
     *
     * @param c The case to display information about.
     */
    void displayInfoCase(Case* c) const;

    /**
     * @brief Gets the bank object.
     *
     * The bank is a special player that manages money and properties not owned by regular players.
     *
     * @return A pointer to the bank player.
     */
    Player* getBank() const;

private:
    Player* m_bank;                      ///< Pointer to the bank player.
    std::vector<Player*> m_player_list;  ///< List of players in the game.
    int m_house_count;                   ///< Total number of houses in the game.
    int m_hotel_count;                   ///< Total number of hotels in the game.
    unsigned int m_current_player;       ///< Index of the current player.
};
