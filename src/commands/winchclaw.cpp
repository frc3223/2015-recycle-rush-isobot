#include "commands/winchclaw.hpp"
#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
WinchClaw::WinchClaw()
    : Base{"WinchClaw"} {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
  Requires(winch_claw_);
}

// Called just before this Command runs the first time
auto WinchClaw::Initialize() -> void {
  winch_claw_->set(subsystems::WinchDir::kUp);
}

// Called repeatedly when this Command is scheduled to run
auto WinchClaw::Execute() -> void {

}

// Make this return true when this Command no longer needs to run execute()
auto WinchClaw::IsFinished() -> bool {
  return false;
}

auto WinchClaw::done() -> void {
  winch_claw_->set(subsystems::WinchDir::kUp);
}

// Called once after isFinished returns true
auto WinchClaw::End() -> void {
  done();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
auto WinchClaw::Interrupted() -> void {
  done();
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
