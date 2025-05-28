#pragma once
#include "orb.h"

class SpiritOrb : public Orb {
public:
	SpiritOrb(const std::string& name, int energy, const std::string& position)
		:Orb(name, "Spirit", energy, position) {
	}

	void display() const override;
};
