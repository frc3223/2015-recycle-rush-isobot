#include "commands/winchdigital.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
WinchDigital::WinchDigital(subsystems::WinchDir dir)
    : Base{"WinchDigital"}, dir_{dir}, power_{0.f} {
  Requires(winch_);
}

auto WinchDigital::Initialize() -> void {
  power_ = 0.f;
}

auto WinchDigital::Execute() -> void {
  switch (dir_) {
    case subsystems::WinchDir::kUp:
      if (power_ < 0.5f) {
        power_ += 0.1f;
      }
      break;
    case subsystems::WinchDir::kDown:
      if (power_ > -0.5f) {
        power_ -= 0.1f;
      }
      break;
  }
  winch_->set(power_);
}

auto WinchDigital::IsFinished() -> bool {
  return false;
}

auto WinchDigital::done() -> void {
  winch_->set(0.f);
}

auto WinchDigital::End() -> void {
  done();
}
auto WinchDigital::Interrupted() -> void {
  done();
}
}
}
}
