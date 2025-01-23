#include "Case.hpp"

class Land : public Case
{
public:
	Land(const std::string name, int value);
	void onLanding(Player* landingPlayer);

private:
	Player* m_owner;
	int m_value;
	int m_rent;
};