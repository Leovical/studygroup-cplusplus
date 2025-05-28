#include <iostream>
#include <memory>
#include <string>
#include "fireOrb.h"
#include "shadowOrb.h"
#include "iceOrb.h"
#include "spiritOrb.h"
#include "orbManager.h"

int main() {
	OrbManager manager;
	int option;

	do {
		std::cout << "\n=== Great Wizard's Tower ===\n";
		std::cout << "1. Add Orb\n";
		std::cout << "2. Show All Orbs\n";
		std::cout << "3. Find Orbs By Name\n";
		std::cout << "4. Exit\n";
		std::cout << "Choose an option: ";
		std::cin >> option;
		std::cin.ignore(); 

		if (option == 1) {
			std::string name, position;
			int energy, typeOption;

			std::cout << "Orb Name: ";
			std::getline(std::cin, name);
			std::cout << "Orb Position: ";
			std::getline(std::cin, position);

			std::cout << "Orb's Energy Level: ";
			std::cin >> energy;
			std::cout << "Choose the energy type:\n";
			std::cout << "1. Fire\n2. Shadow\n3. Spirit\n4. Ice\n";
			std::cin >> typeOption;
			std::cin.ignore();

			if (typeOption == 1) {
				manager.addOrb(std::make_unique<FireOrb>(name, energy, position));
			}
			else if (typeOption == 2) {
				manager.addOrb(std::make_unique<ShadowOrb>(name, energy, position));
			}
			else if (typeOption == 3) {
				manager.addOrb(std::make_unique<SpiritOrb>(name, energy, position));
			}
			else if (typeOption == 4) {
				manager.addOrb(std::make_unique<IceOrb>(name, energy, position));
			}
		}
		else if (option == 2) {
			manager.displayAll();
		}
		else if (option == 3) {
			std::string searchName;
			std::cout << "Search Orb's Name: ";
			std::getline(std::cin, searchName);

			Orb* orb = manager.findOrbByName(searchName);
			if (orb) {
				orb->display();
			}
			else {
				std::cout << "Orb Not Found!\n";
			}
		}
	} while (option != 4); {
		std::cout << "Exiting...";
	}

	return 0;
}