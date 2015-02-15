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

auto Brake::Initialize() -> void {
}

auto Brake::Execute() -> void {
  std::pair<double, double> accel_xy{oi_->accelerometer_->GetX(), oi_->accelerometer_->GetY()};
  std::pair<double, double> accel_rt{std::hypot(accel_xy.first, accel_xy.second), std::atan2(
      accel_xy.second, accel_xy.first) - oi_->accelerometer_angle_};
  std::pair<double, double> wheels{-std::cos(accel_rt.second)
      * (std::signbit(std::sin(accel_rt.first)) ? 1 : -1) * std::min(accel_rt.first, 1.), std::cos(
      accel_rt.second) * (std::signbit(std::sin(accel_rt.first)) ? 1 : -1)
      * std::min(accel_rt.first, 1.)};
  drive_->set(wheels);
}

auto Brake::IsFinished() -> bool {
  return false;
}

auto Brake::End() -> void {
}

auto Brake::Interrupted() -> void {
}
}
}
}
