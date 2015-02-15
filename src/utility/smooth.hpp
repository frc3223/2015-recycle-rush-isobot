#ifndef RETROBOTICS_UTILITY_SMOOTH_HPP
#define RETROBOTICS_UTILITY_SMOOTH_HPP

namespace utility {
template<typename N>
struct Smooth {
  N value;
  N step;
  Smooth& operator=(N new_value) {
    if (std::signbit(new_value)) {  // negative
      value = std::max(value-step, new_value);
    } else {  // positive
      value = std::min(value+step, new_value);
    }
    return *this;
  }
  auto force(N new_value) -> void {
    value = new_value;
  }
};
}  // namespace utility

#endif
