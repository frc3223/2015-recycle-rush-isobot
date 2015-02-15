#ifndef RETROBOTICS_ISOBOT_COMMANDS_BASE_CLEAN_HPP
#define RETROBOTICS_ISOBOT_COMMANDS_BASE_CLEAN_HPP

#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
class BaseClean : public Base {
 public:
  BaseClean(char const* name);
  auto Initialize() -> void;
  auto Execute() -> void;
  auto IsFinished() -> bool;
  auto finish() -> void;
  auto End() -> void;
  auto Interrupted() -> void;
};
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics

#endif
