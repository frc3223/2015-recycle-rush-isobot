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
  void InitDefaultCommand();
  template<int n>
  void set_wheel(float power);
  void set(std::tuple<float, float> powers);
  void tank_drive(auto values, bool squared_inputs);
};
}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

#include "subsystems/drive.ipp"

#endif
