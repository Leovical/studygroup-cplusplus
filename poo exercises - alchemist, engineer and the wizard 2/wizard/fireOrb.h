#pragma once
#include "orb.h"

class FireOrb : public Orb {
public: 
	FireOrb(const std::string& name, int energy, const std::string& position)
		:Orb(name, "Fire", energy, position) {
	}

	void display() const override;
};
