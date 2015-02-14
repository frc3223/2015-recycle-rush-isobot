#ifndef RETROBOTICS_COMMANDS_WINCH_MAINTAIN_HPP
#define RETROBOTICS_COMMANDS_WINCH_MAINTAIN_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchMaintain : public Base {
 public:
  WinchMaintain(subsystems::WinchDir dir);
  auto Initialize() -> void;
  auto Execute() -> void;
  auto IsFinished() -> bool;
  auto End() -> void;
  auto Interrupted() -> void;
};
}
}
}

#endif
