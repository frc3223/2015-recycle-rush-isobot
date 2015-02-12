#include "commands/manualwinch.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
ManualWinch::ManualWinch()
    : Base{"ManualWinch"} {
  Requires(winch_);
}

auto ManualWinch::Initialize() -> void {
}

auto ManualWinch::Execute() -> void {
  winch_->set(control::get<control::Winch>(oi_->main_joy_));
}

auto ManualWinch::IsFinished() -> bool {
  return false;
}

auto ManualWinch::End() -> void {
}

auto ManualWinch::Interrupted() -> void {
}
}
}
}
