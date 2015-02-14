#include "subsystems/winch.hpp"
#include "commands/winchmaintain.hpp"
#include <Compressor.h>
#include <Encoder.h>
#include <cstdint>
#include <cmath>
#include <algorithm>

namespace retrobotics {
namespace isobot {
namespace subsystems {
Winch::Winch()
    : Subsystem{"Winch"}, motor_{new Talon{2}}, encoder_{new Encoder{1, 2}}, previous_encoder_{0} {
}

auto Winch::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::WinchMaintain{});
}

auto Winch::maintain() -> void {
  auto current_encoder = encoder_->Get();
  auto previous_encoder = previous_encoder_;
  previous_encoder_ = current_encoder;
  motor_->Set(-previous_encoder);
}

auto Winch::set(float value) -> void {
  auto current_encoder = encoder_->Get();
  previous_encoder_ = current_encoder;
  if (std::signbit(value)) {
    if (current_encoder < -1700)
      return;
  } else {
    if (current_encoder > 0)
      return;
  }
  motor_->Set(std::min(value + .1f, 1.f));
}
}
}
}

