#include "observator/observator.hpp"
#include "bench.hpp"
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

#include <dlfcn.h>

int observator_initialize() {
	const std::experimental::filesystem::path perspectives_folder{PERSPECTIVES_PATH};

	std::cout << "loading perspective plugins from " << PERSPECTIVES_PATH << std::endl;
	for(auto const& directory_entry: std::experimental::filesystem::directory_iterator{perspectives_folder})
	{
		if (!std::experimental::filesystem::is_directory(directory_entry))
			continue;

		const std::experimental::filesystem::path perspective_plugin_name = directory_entry.path().filename().append(".so");
		const char * perspective_plugin_path =  (directory_entry.path() / perspective_plugin_name).c_str();

		void *perspective_plugin_dl = dlopen(perspective_plugin_path, RTLD_LAZY);
		if (perspective_plugin_dl) {
			Perspective& (*perspective_initialize)() = (Perspective& (*)())dlsym(perspective_plugin_dl, "perspective_initialize" );
				if (perspective_initialize) {
					Perspective &perspective_instance = perspective_initialize();
				}
		}
	}

	if (!bench.observator.perspectives.size()) {
		std::cout << "there are no loaded perspectives!" << std::endl;
		return EXIT_FAILURE;
	}
}
