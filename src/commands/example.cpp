#include "commands/example.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
Example::Example()
    : Base{"Example"} {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Example::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Example::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Example::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void Example::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Example::Interrupted() {

}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
