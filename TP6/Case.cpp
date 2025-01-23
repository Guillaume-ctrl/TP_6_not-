#include "Case.hpp"

Case::Case(const std::string& name) : m_name(name)
{

}

inline std::string Case::getName() const
{
	return this->m_name;
}

Case* Case::getNextCase() const
{
	return this->m_next_case;
}

Case* Case::getPreviousCase() const
{
	return this->m_previous_case;
}

void Case::setNextCase(Case* _case)
{
	this->m_next_case = _case;
}

void Case::setPreviousCase(Case* _case)
{
	this->m_previous_case = _case;
}
