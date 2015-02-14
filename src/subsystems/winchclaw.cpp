#include "subsystems/winchclaw.hpp"
#include "commands/winchclaw.hpp"
#include <Solenoid.h>
#include <Compressor.h>
#include <cmath>
#include <algorithm>

namespace retrobotics {
namespace isobot {
namespace subsystems {
WinchClaw::WinchClaw()
    : Subsystem{"WinchClaw"}, up_{new Solenoid{1}}, down_{new Solenoid{2}} {
  compressor_ = new Compressor{0};
}

auto WinchClaw::InitDefaultCommand() -> void {
  SetDefaultCommand(new commands::WinchClaw{true});
}

auto WinchClaw::set(WinchDir dir) -> void {
  switch (dir) {
    case WinchDir::kUp:
      up_->Set(true);
      down_->Set(false);
      break;
    case WinchDir::kDown:
      up_->Set(false);
      down_->Set(true);
      break;
  }
}
}
}
}

