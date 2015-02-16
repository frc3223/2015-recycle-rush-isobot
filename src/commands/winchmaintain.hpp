#ifndef RETROBOTICS_ISOBOT_COMMANDS_WINCH_MAINTAIN_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_WINCH_MAINTAIN_HPP

#include "base/commands_baseclean.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class WinchMaintain : public BaseClean {
 public:
  WinchMaintain();
  auto Execute() -> void;
};
}
}
}

#endif
