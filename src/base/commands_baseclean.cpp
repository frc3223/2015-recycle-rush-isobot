#include "base/commands_baseclean.hpp"
#include "base/commands_base.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
BaseClean::BaseClean(char const* name)
    : Base{name} {
}
auto BaseClean::Initialize() -> void {
}
auto BaseClean::Execute() -> void {
}
auto BaseClean::IsFinished() -> bool {
  return false;
}
auto BaseClean::finish() -> void {
}
auto BaseClean::End() -> void {
  finish();
}
auto BaseClean::Interrupted() -> void {
  finish();
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
