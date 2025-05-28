#include "spiritOrb.h"
#include <iostream>

void SpiritOrb::display() const {
	std::cout << "Spirit Orb: " << getName() << "\n";
	std::cout << "Energy: " << getEnergy() << "\n";
	std::cout << "Position: " << getPosition() << "\n";
}