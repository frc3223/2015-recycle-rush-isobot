#ifndef RETROBOTICS_COMMANDS_WINCH_DIGITAL_HPP
#define RETROBOTICS_COMMANDS_WINCH_DIGITAL_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchDigital : public Base {
 private:
  subsystems::WinchDir dir_;
  float power_;
 public:
  WinchDigital(subsystems::WinchDir dir);
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
