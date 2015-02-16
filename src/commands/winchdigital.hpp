#ifndef RETROBOTICS_ISOBOT_COMMANDS_WINCH_DIGITAL_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_WINCH_DIGITAL_HPP

#include "base/commands_baseclean.hpp"
#include "utility/smooth.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchDigital : public BaseClean {
 private:
  subsystems::WinchDir dir_;
  utility::Smooth<float> power_;
 public:
  WinchDigital(subsystems::WinchDir dir);
  auto Initialize() -> void;
  auto Execute() -> void;
  auto done() -> void;
};
}
}
}

#endif
