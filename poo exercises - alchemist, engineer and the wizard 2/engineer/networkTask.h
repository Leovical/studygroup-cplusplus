#pragma once
#include "task.h"
#include <iostream>

class NetworkTask : public Task {
public:
	NetworkTask(const std::string& name, double expectedTime)
		:Task(name, expectedTime) {
	}

	void execute() const override;
};