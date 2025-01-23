#include <string>
#include "Player.hpp"

/**
 * @brief base class of a Case
 */

enum Couleur {
	ROUGE     = 0x00,
	BLEU      = 0x01,
	CIAN      = 0x02,
	VERT      = 0x03,
	MAUVE     = 0x04,
	ROSE      = 0x05,
	ORANGE    = 0x06,
	JAUNE     = 0x07,
};

class Case
{
public:
	/**
	 * @brief Constructor
	 * @param name Name of the case
	 */
	Case(const std::string& name);

	/**
	 * @brief Get the name of the case
	 * @return the name of the case
	 */
	std::string getName() const;

	/**
	 * @brief Virtual method called upon a player landing
	 * @param landingPlayer the player that landed
	 */
	virtual void onLanding(Player* landingPlayer) = 0;

private:
	/**
	 * @brief Name of the player
	 */
	std::string m_name;
	unsigned int m_taxe;
	Couleur m_couleur;

};