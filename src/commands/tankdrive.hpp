#ifndef RETROBOTICS_ISOBOT_COMMANDS_TANK_DRIVE_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_TANK_DRIVE_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class TankDrive : public Base {
 public:
  TankDrive();
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
