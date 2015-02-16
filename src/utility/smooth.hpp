#ifndef RETROBOTICS_UTILITY_SMOOTH_HPP
#define RETROBOTICS_UTILITY_SMOOTH_HPP

namespace utility {
template<typename N>
struct Smooth {
  N value;
  N step;
  N set(N new_value) {
    return value =
        (new_value >= value) ? std::min(value + step, new_value) : std::max(value - step, new_value);
  }
  Smooth& operator++() {
    value += step;
    return *this;
  }
  Smooth& operator--() {
    value -= step;
    return *this;
  }
  auto force(N new_value) -> void {
    value = new_value;
  }
};
}  // namespace utility

#endif
