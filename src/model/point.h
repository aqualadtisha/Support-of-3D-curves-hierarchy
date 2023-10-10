#ifndef SUPPORT_OF_3D_CURVES_HIERARCHY_POINT_H
#define SUPPORT_OF_3D_CURVES_HIERARCHY_POINT_H

#include <iostream>

namespace curves {

class Point {
 public:
  Point() = default;
  Point(double x, double y, double z) : x_(x), y_(y), z_(z){};
  Point(double x, double y) : x_(x), y_(y), z_(0){};
  ~Point() = default;

  Point(const Point& other) = default;

  Point(Point&& other) noexcept;

  Point& operator=(const Point& other) noexcept;

  Point& operator=(Point&& other) noexcept;

  [[nodiscard]] double GetX() const { return x_; }
  [[nodiscard]] double GetY() const { return y_; }
  [[nodiscard]] double GetZ() const { return z_; }

 private:
  double x_ = 0;
  double y_ = 0;
  double z_ = 0;

  void Swap(Point& other) noexcept;
  void Clear();
};

}  // namespace curves

#endif  // SUPPORT_OF_3D_CURVES_HIERARCHY_POINT_H
