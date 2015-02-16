#ifndef RETROBOTICS_ISOBOT_COMMANDS_BRAKE_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_BRAKE_HPP

#include "base/commands_baseclean.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class Brake : public BaseClean {
 public:
  Brake();
  auto Execute() -> void;
};
}
}
}

#endif
