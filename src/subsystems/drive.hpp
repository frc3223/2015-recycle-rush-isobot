#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_DRIVE_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_DRIVE_HPP

#include <Commands/Subsystem.h>
#include <tuple>
#include <Talon.h>
#include <RobotDrive.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
class Drive : public Subsystem {
 private:
  std::tuple<Talon*, Talon*> wheels_;
  RobotDrive* drive_;
 public:
  Drive();
  auto InitDefaultCommand() -> void;
  template<int n>
  auto set_wheel(float power) -> void;
  auto set(std::tuple<float, float> powers) -> void;
  template<typename Container>
  auto tank_drive(Container values, bool squared_inputs) -> void;
};
}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

#include "subsystems/drive.ipp"

#endif
