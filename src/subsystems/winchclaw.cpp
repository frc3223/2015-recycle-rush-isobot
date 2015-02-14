#include "subsystems/winchclaw.hpp"
#include "commands/winchclaw.hpp"
#include <Compressor.h>
#include <Encoder.h>
#include <cmath>
#include <algorithm>

namespace retrobotics {
namespace isobot {
namespace subsystems {
WinchClaw::WinchClaw()
    : Subsystem{"WinchClaw"}, relay_up_{new Relay{0}}, relay_down_{new Relay{1}} {
  compressor_ = new Compressor{0};
}

auto WinchClaw::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::WinchClaw{});
}

auto WinchClaw::set(WinchDir dir) -> void {
  switch (dir) {
    case WinchDir::kUp:
      relay_up_->Set(Relay::kOn);
      relay_down_->Set(Relay::kOff);
      break;
    case WinchDir::kDown:
      relay_up_->Set(Relay::kOff);
      relay_down_->Set(Relay::kOn);
      break;
  }
}
}
}
}

