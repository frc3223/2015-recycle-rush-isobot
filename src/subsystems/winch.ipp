#ifndef RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_IPP
#define RETROBOTICS_ISOBOT_SUBSYSTEMS_WINCH_IPP

#include "subsystems/winch.hpp"
#include <cstdint>
#include <cmath>

namespace retrobotics {
namespace isobot {
namespace subsystems {
template<typename N>
auto Winch::in_bounds(int32_t current_encoder, N direction) -> bool {
  if (std::signbit(direction)) { // down
    if (current_encoder > bottom_bound_)
      return false;
  } else { // up
    if (current_encoder < top_bound_)
      return false;
  }
  return true;
}
}
}
}

#endif
