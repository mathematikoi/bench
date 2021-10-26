#include "observator/observator.hpp"
#include "bench.hpp"
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

int observator_initialize() {
	const std::experimental::filesystem::path perspectives_folder{PERSPECTIVES_PATH};

	std::cout << "loading perspective plugins from " << PERSPECTIVES_PATH << std::endl;
	for(auto const& dir_entry: std::experimental::filesystem::directory_iterator{perspectives_folder})
	{
		if (!std::experimental::filesystem::is_directory(dir_entry))
			continue;
		std::cout << dir_entry << '\n';
	}

	if (!bench.observator.perspectives.size()) {
		std::cout << "there are no loaded perspectives!" << std::endl;
		return EXIT_FAILURE;
	}
}
