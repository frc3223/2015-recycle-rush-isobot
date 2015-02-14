#include "subsystems/arm.hpp"
#include <Commands/Subsystem.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
Arm::Arm()
    : Subsystem{"Arm"}, motor_{new Talon{3}} {

}

auto Arm::InitDefaultCommand() -> void {
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new MySpecialCommand());
}

auto Arm::set(float value) -> void {
  motor_->Set(value);
}

}// namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

