#pragma once
#include <string>

class Task {
public:
	Task(const std::string& description);

	void markDone();
	bool isDone() const;
	std::string getDescription() const;

private:
	std::string description;
	bool done;
};
