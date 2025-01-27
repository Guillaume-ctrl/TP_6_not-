#ifndef DICE_H
#define DICE_H

#include <random>

/**
 * @class Dice
 * @brief Represents a dice that can be rolled to generate random numbers.
 *
 * The Dice class provides functionality to simulate a dice roll with a specified
 * number of sides. It uses a Mersenne Twister random number generator to produce
 * uniformly distributed random numbers.
 */
class Dice {
public:
    /**
     * @brief Constructor for the Dice class.
     *
     * Initializes the dice with a specified number of sides and sets up
     * the random number generator and uniform distribution.
     *
     * @param sides Number of sides on the dice (default: 6).
     */
    Dice(int sides = 6);

    /**
     * @brief Rolls the dice and returns a random number.
     *
     * Generates a random number between 1 and the number of sides on the dice.
     *
     * @return A random integer between 1 and the number of sides.
     */
    int roll();

private:
    int m_sides;                        ///< Number of sides on the dice.
    std::mt19937 m_rng;                 ///< Mersenne Twister random number generator.
    std::uniform_int_distribution<int> m_distribution; ///< Uniform distribution for dice rolls.
};

/**
 * @brief A global instance of the Dice class for general use.
 */
extern class Dice DDice;

#endif // DICE_H
