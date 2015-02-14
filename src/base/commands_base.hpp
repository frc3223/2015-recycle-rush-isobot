#ifndef RETROBOTICS_ISOBOT_COMMANDS_BASE_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_BASE_HPP

#include <string>
#include <Commands/Command.h>
#include "subsystems/drive.hpp"
#include "subsystems/winch.hpp"
#include "subsystems/arm.hpp"
#include "control/oi.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
/**
 * The base for all commands. All atomic commands should subclass Base.
 * Base stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use Base.examplesubsystem
 */
class Base : public Command {
 public:
  Base(char const *name);
  Base();
  static void init();
  // Create a single static instance of all of your subsystems
  static subsystems::Drive* drive_;
  static subsystems::Winch* winch_;
  static subsystems::WinchClaw* winch_claw_;
  static subsystems::Arm* arm_;
  static control::OI* oi_;
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
