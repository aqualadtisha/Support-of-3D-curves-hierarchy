#include "figures.h"

#include <cmath>

///// ----------- Ellipse ----------- ////

bool curves::Ellipse::Fill(double x, double y, double z, double r,
                           double small_r) {
  if (r <= 0 || small_r <= 0 || z != 0) return false;

  center_ = std::move(Point(x, y, z));
  small_radius_ = small_r;
  big_radius_ = r;

  return true;
}

curves::Point curves::Ellipse::GetPoint(double t) {
  double x = big_radius_ * std::cos(t);
  double y = small_radius_ * std::sin(t);
  Point p(x, y);

  return p;
}

curves::Point curves::Ellipse::GetFirstDerivative(double t) {
  double dx = -big_radius_ * std::sin(t);
  double dy = small_radius_ * std::cos(t);
  Point p(dx, dy, 0);

  return p;
}

void curves::Ellipse::PrintPoint(double t) {
  Point p = GetPoint(t);
  std::cout << "Point xyz: " << p.GetX() << " " << p.GetY() << " " << p.GetZ()
            << std::endl;
}

void curves::Ellipse::PrintFirstDerivative(double t) {
  Point v = GetFirstDerivative(t);
  std::cout << "Derivative xyz: " << v.GetX() << " " << v.GetY() << " "
            << v.GetZ() << std::endl;
}

int curves::Ellipse::GetType() const { return kEllipse; }

double curves::Ellipse::GetRadius() const {
  return big_radius_;
}  /// big - radius + smal - smal_radius;

///// ----------- Circle ----------- ////

bool curves::Circle::Fill(double x, double y, double z, double r, double b_r) {
  if (b_r != r || r <= 0 || z != 0) return false;

  center_ = std::move(Point(x, y));
  radius_ = r;

  return true;
}

curves::Point curves::Circle::GetPoint(double t) {
  double x = radius_ * std::cos(t);
  double y = radius_ * std::sin(t);
  Point p(x, y);

  return p;
}
curves::Point curves::Circle::GetFirstDerivative(double t) {
  double dx = -radius_ * std::sin(t);
  double dy = radius_ * std::cos(t);
  Point p(dx, dy, 0);

  return p;
}
void curves::Circle::PrintPoint(double t) {
  Point p = GetPoint(t);
  std::cout << "Point xyz: " << p.GetX() << " " << p.GetY() << " " << p.GetZ()
            << std::endl;
}
void curves::Circle::PrintFirstDerivative(double t) {
  Point v = GetFirstDerivative(t);
  std::cout << "Derivative xyz: " << v.GetX() << " " << v.GetY() << " "
            << v.GetZ() << std::endl;
}
int curves::Circle::GetType() const { return kCircle; }

double curves::Circle::GetRadius() const { return radius_; }

///// ----------- Helix ----------- ////

bool curves::Helix::Fill(double x, double y, double z, double r, double s) {
  if (s <= 0 || r <= 0) return false;  ///  || p.z_ != 0    s ?????

  center_ = std::move(Point(x, y, z));
  radius_ = r;
  step_ = s;

  return true;
}

curves::Point curves::Helix::GetPoint(double t) {
  double x = radius_ * std::cos(t);
  double y = radius_ * std::sin(t);
  t = (t >= 2 * M_PI) ? t / 2 * M_PI : t * 1;
  double z = step_ * t;
  Point p(x, y, z);

  return p;
}
curves::Point curves::Helix::GetFirstDerivative(double t) {
  double dx = -radius_ * std::sin(t);
  double dy = radius_ * std::cos(t);
  t = (t >= 2 * M_PI) ? t / 2 * M_PI : t * 1;
  double dz = step_ * t;
  Point p(dx, dy, dz);

  return p;
}

void curves::Helix::PrintPoint(double t) {
  Point p = GetPoint(t);
  std::cout << "Point xyz: " << p.GetX() << " " << p.GetY() << " " << p.GetZ()
            << std::endl;
}

void curves::Helix::PrintFirstDerivative(double t) {
  Point v = GetFirstDerivative(t);
  std::cout << "Derivative xyz: " << v.GetX() << " " << v.GetY() << " "
            << v.GetZ() << std::endl;
}

int curves::Helix::GetType() const { return kHelix; }

double curves::Helix::GetRadius() const { return radius_; }
