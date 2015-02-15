#ifndef RETROBOTICS_COMMANDS_WINCH_DIGITAL_HPP
#define RETROBOTICS_COMMANDS_WINCH_DIGITAL_HPP

#include "base/commands_base.hpp"
#include "utility/smooth.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchDigital : public Base {
 private:
  subsystems::WinchDir dir_;
  utility::Smooth<float> power_;
 public:
  WinchDigital(subsystems::WinchDir dir);
  auto Initialize() -> void;
  auto Execute() -> void;
  auto IsFinished() -> bool;
  auto done() -> void;
  auto End() -> void;
  auto Interrupted() -> void;
};
}
}
}

#endif
