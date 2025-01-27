#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <stdexcept>
#include "PLayer.hpp"

/**
 * @class Bank
 * @brief A generic class to manage a bank's money operations.
 *
 * The Bank class provides methods to add, deduct, and retrieve the current amount
 * of money. It is templated to allow flexibility with different numeric types.
 *
 * @tparam T The type used for money (e.g., int, float, unsigned int).
 */
template<typename T>
class Bank : public Player {
public:
    /**
     * @brief Constructor for the Bank class.
     *
     * Initializes the bank with zero money.
     */
    Bank() : Player("Bank") {
        this->m_money = 0;
    }

    /**
     * @brief Adds money to the bank.
     *
     * Increases the bank's money by the specified amount.
     *
     * @param amount The amount to add.
     */
    void addMoney(T amount) {
        m_money += amount;
    }

    /**
     * @brief Deducts money from the bank.
     *
     * Decreases the bank's money by the specified amount. Throws an exception if
     * the amount to deduct exceeds the available money.
     *
     * @param amount The amount to deduct.
     * @throw std::runtime_error If the amount to deduct exceeds the bank's funds.
     */
    void deductMoney(T amount) {
        if (amount > m_money) {
            throw std::runtime_error("Insufficient funds in the bank!");
        }
        m_money -= amount;
    }

    /**
     * @brief Gets the current amount of money in the bank.
     *
     * @return The current money value.
     */
    T getMoney() const {
        return m_money;
    }
};

/**
 * @brief Global instance of the Bank class for unsigned int type.
 *
 * This provides a predefined bank instance using `unsigned int` as the money type.
 */
Bank<unsigned int> BBank;

#endif // BANK_HPP
