#ifndef RETROBOTICS_ISOBOT_COMMANDS_EXAMPLE_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_EXAMPLE_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class Example : public Base {
 public:
  Example();
  auto Initialize() -> void;
  auto Execute() -> void;
  auto IsFinished() -> bool;
  auto End() -> void;
  auto Interrupted() -> void;
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
