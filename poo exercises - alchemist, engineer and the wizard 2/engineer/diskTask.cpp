#include "diskTask.h"

void DiskTask::execute() const {
	std::cout << "Executing Disking Task: " << getName() << "\n";
	std::cout << "Expected Time: " << getExpectedTime() << " seconds.\n";
}