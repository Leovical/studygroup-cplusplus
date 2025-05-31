#pragma once
#include <string>
#include <vector>
#include <unordered_set>

class MusicManager {
public:
	MusicManager(const std::vector<std::string>& original, const std::vector<std::string>& sadnessOrder);
	void process();

private:
	std::vector<std::string> originalOrder;
	std::vector<std::string> sadnesslOrder;
	std::unordered_set<std::string> currentSongs;

	std::string getMostSadSong() const;
};