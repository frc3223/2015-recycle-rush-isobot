#ifndef RETROBOTICS_ISOBOT_CONTROL_CONTROL_HPP
#define RETROBOTICS_ISOBOT_CONTROL_CONTROL_HPP

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include <type_traits>
#include <utility>
#include <cstdint>

namespace retrobotics {
namespace isobot {
namespace control {
struct DriveX {
  static constexpr bool analog = true;
};
struct DriveY {
  static constexpr bool analog = true;
};
struct DriveLeft {
  static constexpr bool analog = true;
};
struct DriveRight {
  static constexpr bool analog = true;
};
struct Winch {
  static constexpr bool analog = true;
};
struct Arm {
  static constexpr bool analog = true;
};

struct Brake {
  static constexpr bool digital = true;
};
struct WinchUp {
  static constexpr bool digital = true;
};
struct WinchDown {
  static constexpr bool digital = true;
};
struct WinchClaw {
  static constexpr bool digital = true;
};
struct TurnLeft {
  static constexpr bool digital = true;
};
struct TurnRight {
  static constexpr bool digital = true;
};

template<typename C, typename J, std::enable_if_t<C::analog>* = nullptr>
auto get(J joy_c) -> std::enable_if_t<std::is_same<
decltype(joy_c.analog(C {})), float>::value,
float> {
  return joy_c.analog(C{});
}
template<typename C, typename J, std::enable_if_t<C::digital>* = nullptr>
auto get(J joy_c) -> std::enable_if_t<std::is_same<
decltype(joy_c.digital(C {})), std::pair<Joystick* , uint32_t>>::value,
bool> {
  const std::pair<Joystick*, uint32_t> joy_button = joy_c.digital(C{});
  return std::get<0>(joy_button)->GetRawButton(std::get<1>(joy_button));
}
template<typename C, typename J, std::enable_if_t<C::digital>* = nullptr>
auto button(J joy_c) -> std::enable_if_t<std::is_same<
decltype(joy_c.digital(C {})), std::pair<Joystick*, uint32_t>>::value,
JoystickButton*> {
  const std::pair<Joystick*, uint32_t> joy_button = joy_c.digital(C{});
  return new JoystickButton(std::get<0>(joy_button), std::get<1>(joy_button));
}

}  // namespace control
}  // namespace isobot
}  // namespace retrobotics

#endif
