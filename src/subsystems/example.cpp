#include "subsystems/example.hpp"
#include <Commands/Subsystem.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
Example::Example()
    : Subsystem{"Example"} {

}

void Example::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

}// namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

