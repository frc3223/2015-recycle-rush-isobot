#include "commands/tankdrive.hpp"
#include "subsystems/drive.hpp"
#include "control/oi.hpp"

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
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  drive_->tank_drive(std::tuple<float, float>{control::get<control::DriveLeft>(oi_->main_joy_),
      control::get<control::DriveRight>(oi_->main_joy_)}, true);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
