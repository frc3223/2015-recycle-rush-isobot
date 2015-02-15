#include "commands/winchclaw.hpp"
#include "base/commands_baseclean.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
WinchClaw::WinchClaw(bool default_up)
    : BaseClean{"WinchClaw"}, default_up_{default_up} {
  Requires(winch_claw_);
}

auto WinchClaw::Initialize() -> void {
  winch_claw_->set(default_up_ ? subsystems::WinchDir::kDown : subsystems::WinchDir::kUp);
}

auto WinchClaw::done() -> void {
  winch_claw_->set(default_up_ ? subsystems::WinchDir::kUp : subsystems::WinchDir::kDown);
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
