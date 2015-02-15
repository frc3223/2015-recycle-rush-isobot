#ifndef RETROBOTICS_ISOBOT_COMMANDS_ARM_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_ARM_HPP

#include "base/commands_base.hpp"
#include "utility/smooth.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class Arm : public Base {
 private:
  utility::Smooth<float> power_;
 public:
  Arm();
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
