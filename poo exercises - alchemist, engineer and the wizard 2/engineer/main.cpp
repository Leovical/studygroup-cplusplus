#include <iostream>
#include <memory>
#include <string>
#include "diskTask.h"
#include "networkTask.h"
#include "computeTask.h"
#include "taskManager.h"

int main() {
	TaskManager manager;
	int option;

	do {
		std::cout << "\n===Task Manager System===\n";
		std::cout << "1. Add Network Task\n";
		std::cout << "2. Add Disk Task\n";
		std::cout << "3. Add Compute Task\n";
		std::cout << "4. Execute All Tasks\n";
		std::cout << "5. Exit\n";
		std::cout << "Choose an option: ";
		std::cin >> option;
		std::cin.ignore(); //clean buffer

		if (option >= 1 && option <= 3) {
			std::string name;
			double expectedTime;

			std::cout << "Task name: ";
			std::getline(std::cin, name);
			std::cout << "Expected Time (seconds): ";
			std::cin >> expectedTime;
			std::cin.ignore(); //buffer again

			if (option == 1) {
				manager.addTask(std::make_unique<NetworkTask>(name, expectedTime));
			}
			else if (option == 2) {
				manager.addTask(std::make_unique<DiskTask>(name, expectedTime));
			}
			else if (option == 3) {
				manager.addTask(std::make_unique<ComputeTask>(name, expectedTime));
			}
		}
		else if (option == 4) {
			manager.executeAll();
		}

	} while (option != 5);

	std::cout << "Exiting System...\n";
	return 0;
}

