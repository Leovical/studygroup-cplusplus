#pragma once
#include <string>

class Orb {

public:
	Orb(const std::string& name, const std::string& type, int energy, const std::string& position)
		:name(name), type(type), energy(energy), position(position) {
	}

	virtual ~Orb() = default;

	virtual void display() const; //informations about orbs

	//getters and setEnergy
	void setEnergy(int energy) { this->energy = energy; }
	int getEnergy()	const { return energy; };

	std::string getName() const { return name; }
	std::string getType() const { return type; }
	std::string getPosition() const { return position; }

private:
	std::string name;
	std::string type;
	int energy;
	std::string position;
};
