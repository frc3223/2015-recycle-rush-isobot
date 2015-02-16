#include "subsystems/drive.hpp"
#include <Commands/Subsystem.h>
#include <Talon.h>
#include <tuple>
#include <utility>
#include "commands/tankdrive.hpp"
#include "utility/tuple.hpp"

namespace retrobotics {
namespace isobot {
namespace subsystems {
Drive::Drive()
    : Subsystem{"Drive"}, wheels_{new Talon{0}, new Talon{1}},
      drive_{new RobotDrive{std::get<0>(wheels_), std::get<1>(wheels_)}} {
}

auto Drive::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::TankDrive{});
}

template<int n>
auto Drive::set_wheel(float power) -> void {
  std::get<n>(wheels_)->Set(power);
}

auto Drive::set(std::tuple<float, float> powers) -> void {
  auto wheels_powers = utility::tuple::tuple_zip(wheels_, powers);
  utility::tuple::for_each(wheels_powers, [](auto wheel_power) {
    Talon* wheel = wheel_power.first;
    float power = wheel_power.second;
    wheel->Set(power);
  });
}

}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

