#ifndef RETROBOTICS_COMMANDS_BRAKE_HPP
#define RETROBOTICS_COMMANDS_BRAKE_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class Brake : public Base {
 public:
  Brake();
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
