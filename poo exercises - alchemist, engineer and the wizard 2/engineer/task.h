#pragma once
#include <string>

class Task {
public:
	Task(const std::string& name, double expectedTime)
		:name(name), expectedTime(expectedTime) {

	}

	virtual ~Task() = default;

	virtual void execute() const = 0; //abstract mode

	//getters
	std::string getName() const { return name; }
	double getExpectedTime() const { return expectedTime; }

private:
	std::string name;
	double expectedTime;
};