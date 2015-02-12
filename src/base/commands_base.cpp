#include "base/commands_base.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/winch.hpp"
#include "control/oi.hpp"

namespace retrobotics {
namespace isobot {
namespace commands {
// Initialize a single static instance of all of your subsystems to nullptr
subsystems::Drive* Base::drive_ = nullptr;
subsystems::Winch* Base::winch_ = nullptr;
control::OI* Base::oi_ = nullptr;

Base::Base(char const *name)
    : Command{name} {
}

Base::Base()
    : Command{} {

}

void Base::init() {
  // Create a single static instance of all of your subsystems. The following
  // line should be repeated for each subsystem in the project.
  drive_ = new subsystems::Drive{};
  winch_ = new subsystems::Winch{};

  oi_ = new control::OI{};
}
}  // namespace commands
}  // namespace isobot
}  // namespace retrobotics
