#include "subsystems/winch.hpp"
#include "commands/winchanalog.hpp"
#include <Compressor.h>
#include <Encoder.h>
#include <cmath>
#include <algorithm>

namespace retrobotics {
namespace isobot {
namespace subsystems {
Winch::Winch()
    : Subsystem{"Winch"}, motor_{new Talon{2}}, encoder_{new Encoder{1, 2}} {
}

auto Winch::InitDefaultCommand() -> void {
  //SetDefaultCommand(new commands::WinchAnalog{});
}

auto Winch::set(float value) -> void {
  if (std::signbit(value)) {
    if (encoder_->Get() < -1700)
      return;
  } else {
    if (encoder_->Get() > 0)
      return;
  }
  motor_->Set(std::min(value + .1f, 1.f));
}
}
}
}

