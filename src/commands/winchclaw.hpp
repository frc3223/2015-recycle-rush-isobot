#ifndef RETROBOTICS_ISOBOT_COMMANDS_WINCH_CLAW_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_WINCH_CLAW_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class WinchClaw : public Base {
 public:
  WinchClaw();
  void Initialize();
  void Execute();
  bool IsFinished();
  void done();
  void End();
  void Interrupted();
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
