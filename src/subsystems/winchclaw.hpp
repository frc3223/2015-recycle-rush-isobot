#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_CLAW_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_CLAW_HPP

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <Compressor.h>
#include <Solenoid.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
enum class WinchDir {
  kUp,
  kDown,
};

class WinchClaw : public Subsystem {
 private:
  Compressor* compressor_;
  Solenoid* up_;
  Solenoid* down_;
 public:
  WinchClaw();
  auto InitDefaultCommand() -> void;
  auto set(WinchDir dir) -> void;
};
}
}
}

#endif
