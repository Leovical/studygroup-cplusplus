#include "inventory.h"
#include <iostream>

void Inventory::addIngredient(const std::string& name, int quantity, const std::string& description) {
	ingredients[name] = std::make_unique<Ingredient>(name, quantity, description);
}

void Inventory::removeIngredient(const std::string& name) {
	ingredients.erase(name);
}

Ingredient* Inventory::findIngredient(const std::string& name) const {
	auto it = ingredients.find(name);
	if (it != ingredients.end()) {
		return it->second.get();
	}
	return nullptr;
}

void Inventory::listIngredients() const {
	for (const auto& pair : ingredients) {
		std::cout << "Name: " << pair.second->getName() << "\n";
		std::cout << "Quantity: " << pair.second->getQuantity() << "\n";
		std::cout << "Description: " << pair.second->getDescription() << "\n";
		std::cout << "---------------------------\n";
	}
}