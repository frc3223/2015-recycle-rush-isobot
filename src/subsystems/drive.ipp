#ifndef RETROBOTICS_SUBSYSTEMS_DRIVE_IPP
#define RETROBOTICS_SUBSYSTEMS_DRIVE_IPP

#include "drive.hpp"
#include <utility>

namespace retrobotics {
namespace isobot {
namespace subsystems {
void Drive::tank_drive(auto values, bool squared_inputs) {
  drive_->TankDrive(std::get<0>(values), std::get<1>(values), squared_inputs);
}
}  // namespace subsystems
}  // namespace isobot
}  // namepsace retrobotics

#endif /* SRC_SUBSYSTEMS_DRIVE_IPP_ */
