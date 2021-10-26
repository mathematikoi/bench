#ifndef OBSERVATOR_HPP
#define OBSERVATOR_HPP

#include <vector>
#include <utility>

#include <SDL2/SDL.h>

#include "Perspective.hpp"

struct s_perspective {
  void *plugin;
};

struct s_observator {
  size_t width;
  size_t height;
  std::vector<std::pair<struct s_perspective, Perspective*>> perspectives;
};

#define INITIAL_WIDTH 1000
#define INITIAL_HEIGHT 1000
#define WINDOW_TITLE "Bench"

int observator_initialize();

#endif
