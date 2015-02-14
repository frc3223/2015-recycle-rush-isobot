#ifndef RETROBOTICS_SUBSYSTEMS_DRIVE_IPP
#define RETROBOTICS_SUBSYSTEMS_DRIVE_IPP

#include "subsystems/drive.hpp"
#include <utility>

namespace retrobotics {
namespace isobot {
namespace subsystems {
template<typename Container>
auto Drive::tank_drive(Container values, bool squared_inputs) -> void {
  drive_->TankDrive(std::get<0>(values), std::get<1>(values), squared_inputs);
}
}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

#endif
