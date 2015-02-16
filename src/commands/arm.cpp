#include "commands/arm.hpp"
#include "base/commands_baseclean.hpp"
#include "control/control.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
Arm::Arm()
    : BaseClean{"Arm"}, power_{0.0f, 0.1f} {
      Requires(arm_);
}

auto Arm::Initialize() -> void {
  power_.force(0.0f);
}

auto Arm::Execute() -> void {
  arm_->set(power_.set(control::get<control::Arm>(oi_->main_joy_)*0.4f));
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
