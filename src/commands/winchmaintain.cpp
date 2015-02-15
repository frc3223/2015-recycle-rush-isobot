#include "commands/winchmaintain.hpp"
#include "base/commands_baseclean.hpp"
#include "control/control.hpp"
#include <iostream>

namespace retrobotics {
namespace isobot {
namespace commands {
WinchMaintain::WinchMaintain()
    : BaseClean{"WinchMaintain"} {
  Requires(winch_);
}

auto WinchMaintain::Execute() -> void {
  winch_->maintain();
}
}
}
}
