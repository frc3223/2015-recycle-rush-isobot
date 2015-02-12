#include "subsystems/drive.hpp"
#include <Commands/Subsystem.h>
#include <Talon.h>
#include <tuple>
#include <utility>
#include "commands/tankdrive.hpp"
#include "tuple_utils.hpp"

namespace retrobotics {
namespace isobot {
namespace subsystems {
Drive::Drive()
    : Subsystem{"Drive"}, wheels_{new Talon{0}, new Talon{1}},
      drive_{new RobotDrive{std::get<0>(wheels_), std::get<1>(wheels_)}} {
}

void Drive::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new commands::TankDrive{});
}

template<int n>
void Drive::set_wheel(float power) {
  std::get<n>(wheels_)->Set(power);
}

void Drive::set(std::tuple<float, float> powers) {
  auto wheels_powers = tuple_utils::tuple_zip(wheels_, powers);
  tuple_utils::for_each(wheels_powers, [](auto wheel_power) {
    Talon* wheel = wheel_power.first;
    float power = wheel_power.second;
    wheel->Set(power);
  });
}

}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

