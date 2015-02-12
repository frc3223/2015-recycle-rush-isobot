#ifndef RETROBOTICS_COMMANDS_WINCH_ANALOG_HPP
#define RETROBOTICS_COMMANDS_WINCH_ANALOG_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchAnalog : public Base {
 private:
 public:
  WinchAnalog();
  auto Initialize() -> void;
  auto Execute() -> void;
  auto IsFinished() -> bool;
  auto End() -> void;
  auto Interrupted() -> void;
};
}
}
}

#endif
