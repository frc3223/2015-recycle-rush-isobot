#ifndef RETROBOTICS_ISOBOT_COMMANDS_WINCH_CLAW_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_WINCH_CLAW_HPP

#include "base/commands_baseclean.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class WinchClaw : public BaseClean {
 private:
  bool default_up_;
 public:
  WinchClaw(bool default_up = false);
  auto Initialize() -> void;
  auto done() -> void;
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
