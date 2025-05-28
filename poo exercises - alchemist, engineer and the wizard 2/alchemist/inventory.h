#pragma once
#include "Ingredient.h"
#include <memory>
#include <unordered_map>

class Inventory {
private:
	std::unordered_map<std::string, std::unique_ptr<Ingredient >> ingredients;

public:
	void addIngredient(const std::string& name, int quantity, const std::string& description);
	void removeIngredient(const std::string& name);
	Ingredient* findIngredient(const std::string& name) const;
	void listIngredients() const;
};
#pragma once
