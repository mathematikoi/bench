#ifndef UNIVERSE_HPP
# define UNIVERSE_HPP

#include <vector>

#include "Something.hpp"
#include "observator/observator.hpp"
#include "interactor/interactor.hpp"

struct s_universe {
  std::vector<Something*> somethings;
};

#endif
