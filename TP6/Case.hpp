/**
 * @file Case.hpp
 * @brief Declaration of the Case class for the game board.
 */

#pragma once
#include <string>
#include "Player.hpp"

 /**
  * @class Case
  * @brief Represents a case (tile) on the game board.
  */
class Case
{
public:
    /**
     * @brief Constructor for the Case class.
     * @param name Name of the case.
     */
    Case(const std::string& name);

    /**
     * @brief Retrieves the name of the case.
     * @return The name of the case as a std::string.
     */
    std::string getName() const;

    /**
     * @brief Virtual method called when a player lands on this case.
     * @param landingPlayer Pointer to the player who landed on this case.
     * This method must be implemented by derived classes.
     */
    virtual void onLanding(Player* landingPlayer) = 0;

    /**
     * @brief Retrieves the next case in the sequence.
     * @return Pointer to the next case, or nullptr if none exists.
     */
    Case* getNextCase() const;

    /**
     * @brief Retrieves the previous case in the sequence.
     * @return Pointer to the previous case, or nullptr if none exists.
     */
    Case* getPreviousCase() const;

    /**
     * @brief Sets the next case in the sequence.
     * @param _case Pointer to the next case.
     */
    void setNextCase(Case* _case);

    /**
     * @brief Sets the previous case in the sequence.
     * @param _case Pointer to the previous case.
     */
    void setPreviousCase(Case* _case);

private:
    Case* m_next_case;     /**< Pointer to the next case in the sequence. */
    Case* m_previous_case; /**< Pointer to the previous case in the sequence. */

    /**
     * @brief Name of the case.
     */
    std::string m_name;
};
