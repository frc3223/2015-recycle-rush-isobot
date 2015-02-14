#ifndef RETROBOTICS_ISOBOT_COMMANDS_WINCH_CLAW_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_WINCH_CLAW_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class WinchClaw : public Base {
 private:
  bool default_up_;
 public:
  WinchClaw(bool default_up = false);
  auto Initialize() -> void;
  auto Execute() -> void;
  auto IsFinished() -> bool;
  auto done() -> void;
  auto End() -> void;
  auto Interrupted() -> void;
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
