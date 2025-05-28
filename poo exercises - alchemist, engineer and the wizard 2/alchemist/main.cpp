#include "inventory.h"
#include <string>
#include <iostream>

int main() {

	Inventory inventory;
	int option;

	do {
		std::cout << "=== Alchemist Inventory ===\n";
		std::cout << "1. Add Ingredient\n";
		std::cout << "2. Remove Ingredient\n";
		std::cout << "3. Search Ingredient\n";
		std::cout << "4. Exit\n";
		std::cout << "Choose an option: ";
		std::cin >> option;
		std::cin.ignore(); //clean buffer

		if (option == 1) {
			std::string name, description;
			int quantity;

			std::cout << "Ingredient Name: ";
			std::getline(std::cin, name);
			std::cout << "Quantity: ";
			std::cin >> quantity;
			std::cin.ignore(); //clean again
			std::cout << "Description: ";
			std::getline(std::cin, description);

			inventory.addIngredient(name, quantity, description);
		}
		else if (option == 2) {
			std::string name;
			std::cout << "Ingredient Name to Remove: ";
			std::getline(std::cin, name);

			inventory.removeIngredient(name);
		}
		else if (option == 3) {
			std::string name;
			std::cout << "Ingredient Name to Search: ";
			std::getline(std::cin, name);

			auto ingredient = inventory.findIngredient(name);

			if (ingredient) {
				std::cout << "Ingredient found!\n";
				std::cout << "Name: " << ingredient->getName() << " \n";
				std::cout << "Quantity: " << ingredient->getQuantity() << " \n";
				std::cout << "Description: " << ingredient->getDescription() << " \n";
			}
			else {
				std::cout << "Ingredient not found!\n";
			}
		}
	} while (option != 4);

	std::cout << "Exiting...\n";
	return 0;
}
