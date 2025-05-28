#include "fireOrb.h"
#include <iostream>

void FireOrb::display() const {
	std::cout << "Fire Orb: " << getName() << "\n";
	std::cout << "Energy: " << getEnergy() << "\n";
	std::cout << "Position: " << getPosition() << "\n";
}