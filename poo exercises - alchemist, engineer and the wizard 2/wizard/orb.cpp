#include "orb.h"
#include <iostream>

void Orb::display() const {
	std::cout << "Orb: " << name << "\n";
	std::cout << "Type: " << type << "\n";
	std::cout << "Current Energy: " << energy << "\n";
	std::cout << "Position: " << position << "\n";
}