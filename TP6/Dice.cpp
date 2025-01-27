#include "Dice.hpp"
#include <chrono>

Dice::Dice(int sides)
    : m_sides(sides),
    m_rng(static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())),
    m_distribution(1, sides) {}

int Dice::roll() {
    return m_distribution(m_rng);
}

class Dice DDice;