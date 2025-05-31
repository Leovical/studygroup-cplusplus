#include "music.h"
#include <iostream>

MusicManager::MusicManager(const std::vector<std::string>& original, const std::vector<std::string>& sadnessOrder)
	: originalOrder(original), sadnesslOrder(sadnessOrder), currentSongs(original.begin(), original.end()) {
}

std::string MusicManager::getMostSadSong() const {
	for (const auto& song : sadnesslOrder) {
		if (currentSongs.count(song)) {
			return song;
		}
	}
	return ""; //not happen with valid inputs
}

void MusicManager::process() {
	for (const auto& song : originalOrder) {
		std::cout << getMostSadSong() << "\n";
		currentSongs.erase(song);
	}
}