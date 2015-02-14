#include "commands/winchanalog.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
WinchAnalog::WinchAnalog()
    : Base{"WinchAnalog"} {
  Requires(winch_);
}

auto WinchAnalog::Initialize() -> void {
}

auto WinchAnalog::Execute() -> void {
  winch_->set(control::get<control::Winch>(oi_->main_joy_));
}

auto WinchAnalog::IsFinished() -> bool {
  return false;
}

auto WinchAnalog::End() -> void {
}

auto WinchAnalog::Interrupted() -> void {
}
}
}
}
