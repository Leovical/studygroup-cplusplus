#include "taskManager.h"
#include <iostream>

TaskManager::TaskManager() : morning(true) {}

void TaskManager::addTask(const std::string& person, const std::string& description) {
	auto task = std::make_shared<Task>(description);

	if (morning) {
		if (person == "Desmond") {
			desmondTasks.push_back(task);
		}
		else if (person == "Molly") {
			mollyTasks.push_back(task);
		}
	}
	else {
		if (person == "Molly") {
			std::cout << "Pstt! Molly is singing - task assigned to Desmond" << std::endl;
			desmondTasks.push_back(task);
		}
		else if (person == "Desmond") {
			desmondTasks.push_back(task);
		}
	}
}

void TaskManager::listTasks(const std::string& person) const {
	const std::vector<std::shared_ptr<Task>>* taskList = nullptr;

	if (person == "Desmond") {
		taskList = &desmondTasks;
	}
	else if (person == "Molly") {
		taskList = &mollyTasks;
	}

	if (taskList) {
		if (taskList->empty()) {
			std::cout <<  "There's no " << person << "'s tasks at the moment." << std::endl;
			return;
		}

		std::cout << person << "'s Tasks;" << std::endl;
		for (size_t i = 0; i < taskList->size(); ++i) {
			const auto& task = (*taskList)[i];
			std::cout << i << ". [" << (task->isDone() ? "x" : " ") << "]" << task->getDescription() << std::endl;
		}
	}
}

void TaskManager::markTaskDone(const std::string& person, int index) {
	std::vector<std::shared_ptr<Task>>* taskList = nullptr;

	if (person == "Desmond") {
		taskList = &desmondTasks;
	}
	else if (person == "Molly") {
		taskList = &mollyTasks;
	}

	if (taskList && index >= 0 && static_cast<size_t>(index) < taskList->size()) {
		(*taskList)[index]->markDone();
		std::cout << "Task marked as completed!" << std::endl;
	}
	else {
		std::cout << "Invalid index." << std::endl;
	}
}

void TaskManager::switchPeriod() {
	morning = !morning;

	if (!morning) {
		//transition to night
		std::cout << "Molly is singing with the band! Ob-La-Di, Ob-La-Da, life goes on! Brah!" << std::endl;

		//save current Molly's state (just incomplete tasks)
		mollyMorningBackup.clear();
		for (const auto& task : mollyTasks) {
			if (!task->isDone()) {
				mollyMorningBackup.push_back(task);
				desmondTasks.push_back(task);
			}
		}

		mollyTasks.clear();
	}
	else {
		//transition to morning
		mollyTasks = mollyMorningBackup;
		mollyMorningBackup.clear();
	}
}

bool TaskManager::isMorning() const {
	return morning;
}
