#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_HPP

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <Compressor.h>
#include <Relay.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
enum class WinchDir {
  kUp,
  kDown,
};

class Winch : public Subsystem {
 private:
  Talon* winch_motor_;
  Compressor* compressor_;
  Relay* winch_relay_up_;
  Relay* winch_relay_down_;
 public:
  Winch();
  auto InitDefaultCommand() -> void;
  auto set(float value) -> void;
  auto claw(WinchDir dir) -> void;
};
}
}
}

#endif
