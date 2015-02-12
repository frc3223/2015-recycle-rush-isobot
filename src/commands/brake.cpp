#include "commands/brake.hpp"
#include "base/commands_base.hpp"
#include <utility>
#include <cmath>
#include <algorithm>

namespace retrobotics {
namespace isobot {
namespace commands {
Brake::Brake()
    : Base{"Brake"} {
  Requires(drive_);
}

// Called just before this Command runs the first time
auto Brake::Initialize() -> void {
}

// Called repeatedly when this Command is scheduled to run
auto Brake::Execute() -> void {
  std::pair<double, double> accel_xy{oi_->accelerometer_->GetX(), oi_
      ->accelerometer_->GetY()};
  std::pair<double, double> accel_rt{std::hypot(accel_xy.first,
                                                accel_xy.second), std::atan2(
      accel_xy.second, accel_xy.first) - oi_->accelerometer_angle_};
  std::pair<double, double> wheels{-std::cos(accel_rt.second)
      * (std::signbit(std::sin(accel_rt.first)) ? 1 : -1)
      * std::min(accel_rt.first, 1.), std::cos(accel_rt.second)
      * (std::signbit(std::sin(accel_rt.first)) ? 1 : -1)
      * std::min(accel_rt.first, 1.)};
  drive_->set(wheels);
}

// Make this return true when this Command no longer needs to run execute()
auto Brake::IsFinished() -> bool {
  return false;
}

// Called once after isFinished returns true
auto Brake::End() -> void {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
auto Brake::Interrupted() -> void {
}
}
}
}
