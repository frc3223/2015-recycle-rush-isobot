#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_HPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_HPP

#include <Commands/Subsystem.h>
#include <Talon.h>
#include <Compressor.h>
#include <Relay.h>
#include <Encoder.h>
#include <cstdint>

namespace retrobotics {
namespace isobot {
namespace subsystems {
class Winch : public Subsystem {
 private:
  Talon* motor_;
  Encoder* encoder_;
  int32_t previous_encoder_;
  int32_t top_bound_;
  int32_t bottom_bound_;
 public:
  Winch();
  auto InitDefaultCommand() -> void;
  template<typename N>
  auto in_bounds(int32_t current_encoder, N direction) -> bool;
  auto maintain() -> void;
  auto set(float value) -> void;
};
}
}
}

#endif
