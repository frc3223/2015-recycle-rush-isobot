#include "commands/winchmaintain.hpp"
#include "base/commands_base.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
WinchMaintain::WinchMaintain()
    : Base{"WinchMaintain"} {
  Requires(winch_);
}

auto WinchMaintain::Initialize() -> void {
}

auto WinchMaintain::Execute() -> void {
  winch_->maintain();
}

auto WinchMaintain::IsFinished() -> bool {
  return false;
}

auto WinchMaintain::End() -> void {
}
auto WinchMaintain::Interrupted() -> void {
}
}
}
}
