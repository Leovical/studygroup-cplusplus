#include "networkTask.h"

void NetworkTask::execute() const {
	std::cout << "Executing Networking Task: " << getName() << "\n";
	std::cout << "Expected Time: " << getExpectedTime() << " seconds.\n";
}