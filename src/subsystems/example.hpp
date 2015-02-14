#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_EXAMPLE_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_EXAMPLE_HPP

#include <Commands/Subsystem.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
class Example : public Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
 public:
  Example();
  auto InitDefaultCommand() -> void;
};
}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

#endif
