#include "music.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> original(n), sadness(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> original[i];
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> sadness[i];
	}

	MusicManager manager(original, sadness);
	manager.process();

	return 0;
}