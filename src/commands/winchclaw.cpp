#include "commands/winchclaw.hpp"
#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
WinchClaw::WinchClaw(bool default_up)
    : Base{"WinchClaw"}, default_up_{default_up} {
  Requires(winch_claw_);
}

auto WinchClaw::Initialize() -> void {
  winch_claw_->set(default_up_ ? subsystems::WinchDir::kDown : subsystems::WinchDir::kUp);
}

auto WinchClaw::Execute() -> void {
}

auto WinchClaw::IsFinished() -> bool {
  return false;
}

auto WinchClaw::done() -> void {
  winch_claw_->set(default_up_ ? subsystems::WinchDir::kUp : subsystems::WinchDir::kDown);
}

auto WinchClaw::End() -> void {
  done();
}

auto WinchClaw::Interrupted() -> void {
  done();
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
