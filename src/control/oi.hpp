#ifndef RETROBOTICS_ISOBOT_CONTROL_OI_HPP
#define RETROBOTICS_ISOBOT_CONTROL_OI_HPP

#include "control/dualstick.hpp"
#include <interfaces/Accelerometer.h>
#include <Buttons/Button.h>

namespace retrobotics {
namespace isobot {
namespace control {
class OI {
 public:
  typedef DualStick MainJoy;
  OI();
  MainJoy main_joy_;
  Accelerometer* accelerometer_;
  static constexpr double accelerometer_angle_ = 0.;
 private:
  Button* brake_;
  Button* winch_up_;
  Button* winch_down_;
  Button* winch_claw_;
};
}  // namespace control
}  // namespace isobot
}  // namespace retrobotics

#endif
