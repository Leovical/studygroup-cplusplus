#include "ComputeTask.h"

void ComputeTask::execute() const {
	std::cout << "Executing Computing Task: " << getName() << "\n";
	std::cout << "Expected Time: " << getExpectedTime() << " seconds.\n";
}