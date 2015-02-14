#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_HPP

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <Compressor.h>
#include <Relay.h>
#include <Encoder.h>

namespace retrobotics {
namespace isobot {
namespace subsystems {
class Winch : public Subsystem {
 private:
  Talon* motor_;
  Encoder* encoder_;
 public:
  Winch();
  auto InitDefaultCommand() -> void;
  auto set(float value) -> void;
};
}
}
}

#endif
