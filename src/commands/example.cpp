#include "commands/example.hpp"
#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
Example::Example()
    : Base{"Example"} {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(chassis);
}

// Called just before this Command runs the first time
auto Example::Initialize() -> void {

}

// Called repeatedly when this Command is scheduled to run
auto Example::Execute() -> void {

}

// Make this return true when this Command no longer needs to run execute()
auto Example::IsFinished() -> bool {
  return false;
}

// Called once after isFinished returns true
auto Example::End() -> void {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
auto Example::Interrupted() -> void {

}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
