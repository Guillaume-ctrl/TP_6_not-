#include "Case.hpp"

Case::Case(const std::string& name) : m_name(name), m_taxe(0), m_couleur(ROUGE)
{

}

inline std::string Case::getName() const
{
	return this->m_name;
}
