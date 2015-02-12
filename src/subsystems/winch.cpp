#include "subsystems/winch.hpp"
#include "commands/manualwinch.hpp"
#include <Compressor.h>
#include <iostream>
#include <algorithm>

namespace retrobotics {
namespace isobot {
namespace subsystems {
Winch::Winch()
    : Subsystem{"Winch"}, winch_motor_{new Talon{2}}, winch_relay_up_{new Relay{
        0}},
      winch_relay_down_{new Relay{1}} {
  compressor_ = new Compressor{0};
}

auto Winch::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::ManualWinch{});
}

auto Winch::set(float value) -> void {
  winch_motor_->Set(std::min(value + .1f, 1.f));
}

auto Winch::claw(WinchDir dir) -> void {
  switch (dir) {
    case WinchDir::kUp:
      winch_relay_up_->Set(Relay::kOn);
      winch_relay_down_->Set(Relay::kOff);
      break;
    case WinchDir::kDown:
      winch_relay_up_->Set(Relay::kOff);
      winch_relay_down_->Set(Relay::kOn);
      break;
  }
}
}
}
}

