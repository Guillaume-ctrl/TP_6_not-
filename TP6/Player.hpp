#pragma once
#include <string>
#include <vector>
#include <iostream>

/**
 * @enum Cards
 * @brief Represents the different types of cards in the game.
 */
enum Cards {
    CARTE_CHANCE = 0x00,                     ///< Chance card.
    CARTE_CAISSE_DE_COMMUNAUTE = 0x01,       ///< Community Chest card.
    CARTE_ALLER_EN_PRISON = 0x02,            ///< Go to Jail card.
    CARTE_VOUS_ETES_LIBERE_DE_PRISON = 0x03  ///< Get Out of Jail Free card.
};

/**
 * @class Player
 * @brief Represents a player in the game.
 *
 * The Player class manages player properties such as money, position, cards,
 * and prison status. It provides methods for interactions with other players
 * and the game board.
 */
class Player {
public:
    /**
     * @brief Constructor for the Player class.
     *
     * Initializes the player with a given name and default properties.
     *
     * @param name The name of the player.
     */
    Player(const std::string& name);

    /**
     * @brief Transfers money from this player to another player.
     *
     * @param otherPlayer The player receiving the money.
     * @param amount The amount to transfer.
     * @return True if the payment was successful, false otherwise.
     */
    bool payPlayer(Player* otherPlayer, int amount);

    /**
     * @brief Adds money to the player's balance.
     *
     * @param amount The amount to add.
     */
    void addMoney(int amount);

    /**
     * @brief Adds a card to the player's collection.
     *
     * @param card The card to add.
     */
    void addCard(Cards card);

    /**
     * @brief Exchanges a card with another player.
     *
     * @param p The player to exchange with.
     * @param card The card to exchange.
     */
    void exchangeCard(Player* p, Cards card);

    /**
     * @brief Sets the player's position on the game board.
     *
     * @param position The position to set.
     */
    void setPosition(unsigned int position);

    /**
     * @brief Gets the player's current position on the game board.
     *
     * @return The current position.
     */
    unsigned int getPosition();

    /**
     * @brief Gets the player's name.
     *
     * @return The name of the player.
     */
    std::string getName() const;

    /**
     * @brief Gets the player's current money balance.
     *
     * @return The current money value.
     */
    unsigned int getMoneyValue() const;

    /**
     * @brief Deducts money from the player's balance.
     *
     * @param value The amount to deduct.
     * @return The remaining money balance.
     */
    unsigned int setDeductMoney(unsigned int value);

    /**
     * @brief Sets the player's prison status.
     *
     * @param p True if the player is in prison, false otherwise.
     */
    void setInPrison(bool p);

    /**
     * @brief Gets the player's prison status.
     *
     * @return True if the player is in prison, false otherwise.
     */
    bool getInPrison() const;

    /**
     * @brief Sets whether the player is out of the game.
     *
     * @param out True if the player is out, false otherwise.
     */
    void setOut(bool out);

    /**
     * @brief Gets whether the player is out of the game.
     *
     * @return True if the player is out, false otherwise.
     */
    bool getOut();

protected:
    int m_money;                       ///< The player's current money balance.
    std::string m_name;                ///< The player's name.
    unsigned int m_game_position;      ///< The player's current position on the game board.
    std::vector<Cards> m_cartes;       ///< The cards in the player's possession.
    bool m_inPrison;                   ///< True if the player is in prison, false otherwise.
    bool m_out;                        ///< True if the player is out of the game, false otherwise.
};
