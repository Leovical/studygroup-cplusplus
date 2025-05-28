#pragma once
#include "task.h"
#include <iostream>

class ComputeTask : public Task {
public:
	ComputeTask(const std::string& name, double expectedTime)
		: Task(name, expectedTime) {
	}

	void execute() const override;
};
