#pragma once
#include <string>

class Ingredient {
private:
	std::string name;
	int quantity;
	std::string description;

public:
	Ingredient(const std::string& name, int quantity, const std::string& description);

	//getters
	const std::string& getName() const;
	int getQuantity() const;
	const std::string& getDescription() const;
	void setQuantity(int quantity);
};
#pragma once
