#include "shadowOrb.h"
#include <iostream>

void ShadowOrb::display() const {
	std::cout << "Shadow Orb: " << getName() << "\n";
	std::cout << "Energy: " << getEnergy() << "\n";
	std::cout << "Position: " << getPosition() << "\n";
}