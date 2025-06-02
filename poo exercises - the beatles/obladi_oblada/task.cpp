#include "task.h"

//constructor inicializing with the task not done
Task::Task(const std::string& description)
	: description(description), done(false) {
}

void Task::markDone() {
	done = true;
}

bool Task::isDone() const {
	return done;
}

std::string Task::getDescription() const {
	return description;
}