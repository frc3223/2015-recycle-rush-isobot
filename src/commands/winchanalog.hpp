#ifndef RETROBOTICS_COMMANDS_WINCH_ANALOG_HPP
#define RETROBOTICS_COMMANDS_WINCH_ANALOG_HPP

#include "base/commands_baseclean.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchAnalog : public BaseClean {
 private:
 public:
  WinchAnalog();
  auto Execute() -> void;
};
}
}
}

#endif
