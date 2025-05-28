#pragma once
#include "orb.h"
#include <memory>
#include <vector>

class OrbManager {
public:
	void addOrb(std::unique_ptr<Orb> orb);
	void displayAll() const;
	Orb* findOrbByName(const std::string& name);

private:
	std::vector<std::unique_ptr<Orb>> orbs;
};