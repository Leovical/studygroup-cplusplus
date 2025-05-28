#pragma once
#include "task.h"
#include <memory>
#include <vector>

class TaskManager {
public:
	void addTask(std::unique_ptr<Task> task);
	void executeAll();

private:
	std::vector<std::unique_ptr<Task>> tasks;
};