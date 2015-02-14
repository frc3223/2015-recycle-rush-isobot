#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_CLAW_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_CLAW_HPP

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <Compressor.h>
#include <Relay.h>
#include <Encoder.h>

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
  Relay* relay_up_;
  Relay* relay_down_;
 public:
  WinchClaw();
  auto InitDefaultCommand() -> void;
  auto set(WinchDir dir) -> void;
};
}
}
}

#endif
