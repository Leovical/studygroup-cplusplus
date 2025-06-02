#pragma once
#include "task.h"
#include <string>
#include <memory>
#include <vector>

class TaskManager {
public:
	TaskManager();

	void addTask(const std::string& person, const std::string& description);
	void listTasks(const std::string& person) const;
	void markTaskDone(const std::string& person, int index);
	void switchPeriod(); //morning and night
	bool isMorning() const;

private:
	std::vector<std::shared_ptr<Task>> desmondTasks;
	std::vector<std::shared_ptr<Task>> mollyTasks;
	std::vector<std::shared_ptr<Task>> mollyMorningBackup;

	bool morning;
};