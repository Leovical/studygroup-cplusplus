#pragma once
#include "orb.h"

class ShadowOrb : public Orb {
public:
	ShadowOrb(const std::string& name, int energy, const std::string& position)
		:Orb(name, "Shadow", energy, position) {
	}

	void display() const override;
};