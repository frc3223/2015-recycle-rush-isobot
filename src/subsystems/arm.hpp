#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_ARM_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_ARM_HPP

#include <Commands/Subsystem.h>
#include <Talon.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
class Arm : public Subsystem {
 private:
  Talon* motor_;
 public:
  Arm();
  auto InitDefaultCommand() -> void;
  auto set(float value) -> void;
};
}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

#endif
