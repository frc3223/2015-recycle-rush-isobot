#include "control/dualstick.hpp"
#include "control/control.hpp"
#include <Joystick.h>
#include <utility>

namespace retrobotics {
namespace isobot {
namespace control {
DualStick::DualStick(uint32_t port_left, uint32_t port_right)
    : joy_left_{new Joystick{port_left}}, joy_right_{new Joystick{port_right}} {
}

auto DualStick::analog(control::DriveX) const -> float {
  return joy_right_->GetRawAxis(kJoyX);
}

auto DualStick::analog(control::DriveY) const -> float {
  return joy_right_->GetRawAxis(kJoyY);
}
auto DualStick::analog(control::DriveLeft) const -> float {
  return joy_left_->GetRawAxis(kJoyY);
}
auto DualStick::analog(control::DriveRight) const -> float {
  return joy_right_->GetRawAxis(kJoyY);
}
auto DualStick::analog(control::Winch) const -> float {
  return joy_left_->GetRawButton(kButtonCenter)
      - joy_left_->GetRawButton(kButtonDown);
}
auto DualStick::digital(
    control::Brake) const -> std::pair<Joystick*, uint32_t> {
  constexpr auto kButtonCenter = DualStick::kButtonCenter;
  return {joy_right_, kButtonCenter};
}
}  // namespace control
}  // namespace isobot
}  // namespace retrobotics
