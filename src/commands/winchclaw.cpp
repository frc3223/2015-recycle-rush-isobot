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
void WinchClaw::Initialize() {
  winch_claw_->set(subsystems::WinchDir::kUp);
}

// Called repeatedly when this Command is scheduled to run
void WinchClaw::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WinchClaw::IsFinished() {
  return false;
}

void WinchClaw::done() {
  winch_claw_->set(subsystems::WinchDir::kUp);
}

// Called once after isFinished returns true
void WinchClaw::End() {
  done();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchClaw::Interrupted() {
  done();
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
