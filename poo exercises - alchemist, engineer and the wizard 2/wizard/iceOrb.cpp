#include "iceOrb.h"
#include <iostream>

void IceOrb::display() const {
	std::cout << "Ice Orb: " << getName() << "\n";
	std::cout << "Energy: " << getEnergy() << "\n";
	std::cout << "Position: " << getPosition() << "\n";
}