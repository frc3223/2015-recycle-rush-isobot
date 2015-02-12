#include "control/oi.hpp"
#include <BuiltInAccelerometer.h>
#include <Buttons/JoystickButton.h>
#include "commands/brake.hpp"

namespace retrobotics {
namespace isobot {
namespace control {
OI::OI()
    : main_joy_{}, accelerometer_{new BuiltInAccelerometer{}}, brake_{
          control::button<control::Brake>(main_joy_)} {
  // Process operator interface input here.
  brake_->WhileHeld(new commands::Brake{});
}
}  // namespace control
}  // namespace isobot
}  // namespace retrobotics
