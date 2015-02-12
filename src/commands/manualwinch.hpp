#ifndef RETROBOTICS_MANUAL_WINCH_HPP
#define RETROBOTICS_MANUAL_WINCH_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class ManualWinch : public Base {
 public:
  ManualWinch();
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
