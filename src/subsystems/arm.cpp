#include "subsystems/arm.hpp"
#include <Commands/Subsystem.h>
#include "commands/arm.hpp"

namespace retrobotics {
namespace isobot {
namespace subsystems {
Arm::Arm()
    : Subsystem{"Arm"}, motor_{new Talon{3}} {

}

auto Arm::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::Arm{});
}

auto Arm::set(float value) -> void {
  motor_->Set(value);
}

}// namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

