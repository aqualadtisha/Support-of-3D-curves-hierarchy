#include "figures.h"
#include <cmath>

std::shared_ptr<curves::Figures> curves::Figures::CreateFigures(int type) {
  switch (type) {
    case kEllipse : fig_ = std::make_shared<Ellipse>(); return fig_;
    case kCircle : fig_ = std::make_shared<Circle>(); return fig_;
    case kHelix : fig_ = std::make_shared<Helix>(); return fig_;
  }
  return nullptr;
}

///// ----------- Ellipse ----------- ////

bool curves::Ellipse::Fill(curves::Point p, double r, double b_r) {

  if (r <= 0 || b_r <= 0 || !isdigit(r) || !isdigit(b_r)) return false; ///  || p.z_ != 0

  center_ = p; /// center_ = &p
  smal_radii_ = r;
  big_radii_ = b_r;

  return true;
}
curves::Point& curves::Ellipse::GetPoint(double t) {
  double x = big_radii_ * std::cos(t);
  double y = smal_radii_ * std::sin(t);
  Point p(x, y);

  return p;
}
double curves::Ellipse::GetFirstDerivative(double t) {
  return (-smal_radii_ * std::sin(t)) / (big_radii_ * std::cos(t));
}
void curves::Ellipse::PrintPoint(double t) {
  Point p = GetPoint(t);
  std::cout << p.x_ << std::endl;
}
void curves::Ellipse::PrintFirstDerivative(double t) {
  std::cout << GetFirstDerivative(t) << std::endl;
}
int curves::Ellipse::GetType() const { return kEllipse; }

double curves::Ellipse::GetRadius() const { return big_radii_; } /// big - radii + smal - smal_radii;

///// ----------- Circle ----------- ////

bool curves::Circle::Fill(curves::Point p, double r, double b_r) {
  if (!isdigit(r)|| b_r != r || r <= 0 ) return false; ///  || p.z_ != 0

  center_ = p; /// center_ = &p
  radii_ = r;

  return true;
}

curves::Point& curves::Circle::GetPoint(double t) {
  double x = radii_ * std::cos(t);
  double y = radii_ * std::sin(t);
  Point p(x, y);

  return p;
}
double curves::Circle::GetFirstDerivative(double t) {
  return (-radii_ * std::sin(t)) / (radii_ * std::cos(t));
}
void curves::Circle::PrintPoint(double t) {
  Point p = GetPoint(t);
  std::cout << p.x_ << std::endl;
}
void curves::Circle::PrintFirstDerivative(double t) {
  std::cout << GetFirstDerivative(t) << std::endl;
}
int curves::Circle::GetType() const { return kCircle; }

double curves::Circle::GetRadius() const { return radii_; }

///// ----------- Helix ----------- ////

bool curves::Helix::Fill(curves::Point p, double r, double s) {
  if (!isdigit(r) || !isdigit(s) || s <= 0 || r <= 0 ) return false; ///  || p.z_ != 0    s ?????

  center_ = p; /// center_ = &p
  radii_ = r;
  step_ = s;

  return true;
}

curves::Point& curves::Helix::GetPoint(double t) {
  double x = radii_ * std::cos(t);
  double y = radii_ * std::sin(t);
  double z = step_ * t / 2 * M_PI;
  Point p(x, y, z);

  return p;
}
double curves::Helix::GetFirstDerivative(double t) {
  return (-radii_ * std::sin(t)) / (radii_ * std::cos(t));
}
void curves::Helix::PrintPoint(double t) {
  Point p = GetPoint(t);
  std::cout << p.x_ << std::endl;
}
void curves::Helix::PrintFirstDerivative(double t) {
  std::cout << GetFirstDerivative(t) << std::endl;
}
int curves::Helix::GetType() const { return kHelix; }

double curves::Helix::GetRadius() const { return radii_; }