#include "commands/winchdigital.hpp"
#include "base/commands_baseclean.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
WinchDigital::WinchDigital(subsystems::WinchDir dir)
    : BaseClean{"WinchDigital"}, dir_{dir}, power_{0.0f, 0.1f} {
  Requires(winch_);
}

auto WinchDigital::Initialize() -> void {
  power_.force(0.0f);
}

auto WinchDigital::Execute() -> void {
  switch (dir_) {
    case subsystems::WinchDir::kUp:
      power_ = 0.5f;
      break;
    case subsystems::WinchDir::kDown:
      power_ = -0.5f;
      break;
  }
  winch_->set(power_.value);
}

auto WinchDigital::done() -> void {
  winch_->set(0.f);
}
}
}
}
