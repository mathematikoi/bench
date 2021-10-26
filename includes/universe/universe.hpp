#ifndef UNIVERSE_HPP
# define UNIVERSE_HPP

#include <vector>

#include "./Something.hpp"
#include "observator/observator.hpp"
#include "interactor/interactor.hpp"

class Something {
  std::string name;
};

struct s_universe {
  std::vector<Something*> somethings;
};

#endif
