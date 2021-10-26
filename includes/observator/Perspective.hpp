#ifndef SOMETHING_HPP
# define SOMETHING_HPP

#include <string>

class Perspective {
  std::string name;
  virtual int initialize() = 0;
};

#endif
