#include "ingredient.h"

Ingredient::Ingredient(const std::string& name, int quantity, const std::string& description)
	:name(name), quantity(quantity), description(description) {

}

const std::string& Ingredient::getName() const {
	return name;
}

int Ingredient::getQuantity() const {
	return quantity;
}

const std::string& Ingredient::getDescription() const {
	return description;
}

void Ingredient::setQuantity(int quantity) {
	this->quantity = quantity;
}