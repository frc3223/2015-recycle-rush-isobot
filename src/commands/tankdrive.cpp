#include "commands/tankdrive.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
TankDrive::TankDrive()
    : Base{"TankDrive"} {
  Requires(drive_);
}

auto TankDrive::Initialize() -> void {
}

auto TankDrive::Execute() -> void {
  drive_->tank_drive(std::tuple<float, float>{control::get<control::DriveLeft>(oi_->main_joy_),
                         control::get<control::DriveRight>(oi_->main_joy_)},
                     true);
}

auto TankDrive::IsFinished() -> bool {
  return false;
}

auto TankDrive::End() -> void {
}

auto TankDrive::Interrupted() -> void {
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
