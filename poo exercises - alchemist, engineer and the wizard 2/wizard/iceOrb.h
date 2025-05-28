#pragma once
#include "orb.h"

class IceOrb : public Orb {
public:
	IceOrb(const std::string& name, int energy, const std::string& position)
		:Orb(name, "Ice", energy, position) {
	}

	void display() const override;
};
