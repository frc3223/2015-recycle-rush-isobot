#ifndef RETROBOTICS_ISOBOT_COMMANDS_TANK_DRIVE_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_TANK_DRIVE_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class TankDrive : public Base {
 public:
  TankDrive();
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
