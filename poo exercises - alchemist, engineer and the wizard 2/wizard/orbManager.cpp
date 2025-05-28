#include "orbManager.h"
#include <iostream>

void OrbManager::addOrb(std::unique_ptr<Orb> orb) {
	orbs.push_back(std::move(orb));
}

void OrbManager::displayAll() const {
	for (const auto& orb : orbs) {
		orb->display();
		std::cout << "\n";
	}
}

Orb* OrbManager::findOrbByName(const std::string& name) {
	for (const auto& orb : orbs) {
		if (orb->getName() == name) {
			return orb.get();
		}
	}
	return nullptr; // if not found, return null
}