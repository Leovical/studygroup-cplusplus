#include "taskManager.h"

void TaskManager::addTask(std::unique_ptr<Task> task) {
	tasks.push_back(std::move(task));
}

void TaskManager::executeAll() {
	for (const auto& task : tasks) {
		task->execute();
	}
	tasks.clear();
}