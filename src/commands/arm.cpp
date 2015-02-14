#include "commands/arm.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
Arm::Arm()
    : Base{"Arm"} {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
      Requires(arm_);
}

// Called just before this Command runs the first time
void Arm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Arm::Execute() {
  arm_->set(control::get<control::Arm>(oi_->main_joy_));
}

// Make this return true when this Command no longer needs to run execute()
bool Arm::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void Arm::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Arm::Interrupted() {

}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
