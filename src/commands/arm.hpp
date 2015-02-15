#ifndef RETROBOTICS_ISOBOT_COMMANDS_ARM_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_ARM_HPP

#include "base/commands_baseclean.hpp"
#include "utility/smooth.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {

class Arm : public BaseClean {
 private:
  utility::Smooth<float> power_;
 public:
  Arm();
  auto Initialize() -> void;
  auto Execute() -> void;
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
