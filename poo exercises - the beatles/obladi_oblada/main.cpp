#include "taskManager.h"
#include <iostream>
#include <string>

void showMenu(bool isMorning) {
	std::cout << "\n=== Desmond and Molly Jones's MarketPlace ===" << std::endl;
	std::cout << (isMorning ? "[Morning]" : "[Night]") << std::endl;
	std::cout << "1. Add Task" << std::endl;
	std::cout << "2. List Task" << std::endl;
	std::cout << "3. Mark Task as Completed" << std::endl;
	std::cout << "4. Switch Period (morning/night)" << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "Choose an option: ";
}

int main() {
	TaskManager manager;
	int option;

	do {
		showMenu(manager.isMorning());
		std::cin >> option;
		std::cin.ignore(); 

		switch (option) {
		case 1: {
			std::string person, description;
			std::cout << "Who is the task for? (Desmond/Molly): ";
			std::getline(std::cin, person);
			std::cout << "Task description: ";
			std::getline(std::cin, description);
			manager.addTask(person, description);
			break;
		}
		case 2: {
			std::string person;
			int index;
			std::cout << "Whose tasks do you want to see? (Desmond/Molly): ";
			std::getline(std::cin, person);
			manager.listTasks(person);
			break;
		}
		case 3: {
			std::string person;
			int index;
			std::cout << "Whose task is it?  (Desmond/Molly): ";
			std::getline(std::cin, person);
			std::cout << "Task number to mark as complete: ";
			std::cin >> index;
			std::cin.ignore();
			manager.markTaskDone(person, index);
			break;
		}
		case 4: 
			manager.switchPeriod();
			break;
		case 0:
			std::cout << "Shutting down the system. See you soon!" << std::endl;
			break;
		default:
			std::cout << "Invalid Option!" << std::endl;
		}
	} while (option != 0);

	return 0;
}