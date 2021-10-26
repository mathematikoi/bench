#ifndef PERSPECTIVE_HPP
# define PERSPECTIVE_HPP

#include <string>

class Perspective {
  std::string name;
  virtual int initialize() = 0;
};

#endif
