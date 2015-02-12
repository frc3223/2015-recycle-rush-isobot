#include "control/oi.hpp"
#include <BuiltInAccelerometer.h>
#include <Buttons/JoystickButton.h>
#include "commands/brake.hpp"
#include "commands/winchdigital.hpp"

namespace retrobotics {
namespace isobot {
namespace control {
OI::OI()
    : main_joy_{}, accelerometer_{new BuiltInAccelerometer{}}, brake_{
          control::button<control::Brake>(main_joy_)},
      winch_up_{control::button<control::WinchUp>(main_joy_)},
      winch_down_{control::button<control::WinchDown>(main_joy_)} {
  // Process operator interface input here.
  brake_->WhileHeld(new commands::Brake{});
  winch_up_->WhileHeld(new commands::WinchDigital{subsystems::WinchDir::kUp});
  winch_down_->WhileHeld(new commands::WinchDigital{subsystems::WinchDir::kDown});
}
}  // namespace control
}  // namespace isobot
}  // namespace retrobotics
