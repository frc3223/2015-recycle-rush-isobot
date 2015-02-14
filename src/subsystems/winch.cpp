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
    : Subsystem{"Winch"}, motor_{new Talon{2}}, encoder_{new Encoder{1, 2}}, previous_encoder_{0},
      top_bound_{-1170}, bottom_bound_{0} {
}

auto Winch::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::WinchMaintain{});
}

auto Winch::maintain() -> void {
  auto current_encoder = encoder_->Get();
  auto d_encoder = current_encoder - previous_encoder_;
  if (!in_bounds(current_encoder, d_encoder)) motor_->Set(0.f);
  motor_->Set(d_encoder * 0.05f);
}

auto Winch::set(float value) -> void {
  auto current_encoder = encoder_->Get();
  if (!in_bounds(current_encoder, value)) motor_->Set(0.f);
  previous_encoder_ = current_encoder;
  motor_->Set(std::min(value + .1f, 1.f));
}
}
}
}

#include "subsystems/winch.ipp"

