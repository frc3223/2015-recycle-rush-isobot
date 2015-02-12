#ifndef RETROBOTICS_ISOBOT_COMMANDS_EXAMPLE_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_EXAMPLE_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class Example : public Base {
 public:
  Example();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
