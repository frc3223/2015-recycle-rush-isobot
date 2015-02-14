#include "commands/tankdrive.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
TankDrive::TankDrive()
    : Base{"TankDrive"} {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
  Requires(drive_);
}

// Called just before this Command runs the first time
auto TankDrive::Initialize() -> void {

}

// Called repeatedly when this Command is scheduled to run
auto TankDrive::Execute() -> void {
  drive_->tank_drive(std::tuple<float, float>{control::get<control::DriveLeft>(oi_->main_joy_),
                         control::get<control::DriveRight>(oi_->main_joy_)},
                     true);
}

// Make this return true when this Command no longer needs to run execute()
auto TankDrive::IsFinished() -> bool {
  return false;
}

// Called once after isFinished returns true
auto TankDrive::End() -> void {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
auto TankDrive::Interrupted() -> void {

}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
