#ifndef BENCH_HPP
# define BENCH_HPP

#include <iostream>

#include "universe/universe.hpp"
#include "observator/observator.hpp"
#include "interactor/interactor.hpp"

struct s_bench {
  struct s_observator observator;
  struct s_interactor;
  struct s_universe universe;
};

extern struct s_bench bench;

#define PERSPECTIVES_PATH "./perspectives"
#define SOMETHINGS_PATH "./somethings"

#endif
