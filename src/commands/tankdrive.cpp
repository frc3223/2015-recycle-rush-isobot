#include "commands/tankdrive.hpp"
#include "base/commands_baseclean.hpp"
#include "control/control.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
TankDrive::TankDrive()
    : BaseClean{"TankDrive"} {
  Requires(drive_);
}

auto TankDrive::Execute() -> void {
  drive_->tank_drive(std::tuple<float, float>{control::get<control::DriveLeft>(oi_->main_joy_),
                         control::get<control::DriveRight>(oi_->main_joy_)},
                     true);
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
