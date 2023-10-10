#include "point.h"

#include <iostream>

curves::Point::Point(curves::Point&& other) noexcept { Swap(other); }

curves::Point& curves::Point::operator=(const curves::Point& other) noexcept {
  if (this == &other) return *this;

  Point tmp(other);
  Swap(tmp);

  return *this;
}

void curves::Point::Swap(curves::Point& other) noexcept {
  std::swap(x_, other.x_);
  std::swap(y_, other.y_);
  std::swap(z_, other.z_);
}

curves::Point& curves::Point::operator=(curves::Point&& other) noexcept {
  Swap(other);
  other.Clear();

  return *this;
}

void curves::Point::Clear() {
  x_ = 0;
  y_ = 0;
  z_ = 0;
}
