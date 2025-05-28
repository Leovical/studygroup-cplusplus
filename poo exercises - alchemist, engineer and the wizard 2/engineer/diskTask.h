#pragma once
#include "task.h"
#include <iostream>

class DiskTask : public Task {
public: 
	DiskTask(const std::string& name, double expectedTime)
		: Task(name, expectedTime) {
	}

	void execute() const override;
};