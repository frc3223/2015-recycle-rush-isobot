#ifndef RETROBOTICS_ISOBOT_COMMANDS_ARM_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_ARM_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class Arm : public Base {
 public:
  Arm();
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
