#ifndef RETROBOTICS_ISOBOT_CONTROL_DUAL_STICK_HPP
#define RETROBOTICS_ISOBOT_CONTROL_DUAL_STICK_HPP

#include "control/control.hpp"
#include <Joystick.h>
#include <utility>

namespace retrobotics {
namespace isobot {
namespace control {
class DualStick {
 private:
  Joystick* joy_left_;
  Joystick* joy_right_;
  static constexpr uint32_t kJoyX = 0;
  static constexpr uint32_t kJoyY = 1;
  static constexpr uint32_t kJoyWheel = 2;
  static constexpr uint32_t kButtonTrig = 1;
  static constexpr uint32_t kButtonDown = 2;
  static constexpr uint32_t kButtonCenter = 3;
  static constexpr uint32_t kButtonLeft = 4;
  static constexpr uint32_t kButtonRight = 5;
  static constexpr uint32_t kButtonBaseLeftUp = 6;
  static constexpr uint32_t kButtonBaseLeftDown = 7;
  static constexpr uint32_t kButtonBaseDownLeft = 8;
  static constexpr uint32_t kButtonBaseDownRight = 9;
  static constexpr uint32_t kButtonBaseRightDown = 10;
  static constexpr uint32_t kButtonBaseRightUp = 11;
 public:
  DualStick(uint32_t port_left = 0, uint32_t port_right = 1);
  auto analog(control::DriveX) const -> float;
  auto analog(control::DriveY) const -> float;
  auto analog(control::DriveLeft) const -> float;
  auto analog(control::DriveRight) const -> float;
  auto analog(control::Winch) const -> float;
  auto analog(control::Arm) const -> float;
  auto digital(control::Brake) const -> std::pair<Joystick*, uint32_t>;
  auto digital(control::WinchUp) const -> std::pair<Joystick*, uint32_t>;
  auto digital(control::WinchDown) const -> std::pair<Joystick*, uint32_t>;
  auto digital(control::WinchClaw) const -> std::pair<Joystick*, uint32_t>;
};
}  // namespace control
}  // namespace isobot
}  // namespace retrobotics

#endif
