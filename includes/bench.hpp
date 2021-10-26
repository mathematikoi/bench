#ifndef BENCH_HPP
# define BENCH_HPP

#include <iostream>

#include "observator/observator.hpp"
#include "universe/universe.hpp"
#include "interactor/interactor.hpp"

struct s_bench {
  struct s_observator observator;
  struct s_interactor;
  struct s_universe universe;
};

struct s_bench bench;

#endif
