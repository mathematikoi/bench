#ifndef OBSERVATOR_HPP
#define OBSERVATOR_HPP

#include <SDL2/SDL.h>

struct s_observator {
  size_t width;
  size_t height;
};

#define INITIAL_WIDTH 1000
#define INITIAL_HEIGHT 1000
#define WINDOW_TITLE "Bench"

int observator_initialize();

#endif
