#include "commands/winchanalog.hpp"
#include "base/commands_baseclean.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
WinchAnalog::WinchAnalog()
    : BaseClean{"WinchAnalog"} {
  Requires(winch_);
}

auto WinchAnalog::Execute() -> void {
  winch_->set(control::get<control::Winch>(oi_->main_joy_));
}
}
}
}
