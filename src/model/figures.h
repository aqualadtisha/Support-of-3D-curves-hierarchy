#ifndef SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H
#define SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H

#include <utility>

#include "abstract_figure.h"

namespace curves {

class Ellipse : public Figure {
 public:
  Ellipse() = default;
  Ellipse(Point p, double r, double b_r)
      : center_(std::move(p)), small_radius_(r), big_radius_(b_r){};

  bool Fill(double x, double y, double z, double r, double small_r) override;

  Point GetPoint(double t) override;

  Point GetFirstDerivative(double t) override;

  void PrintPoint(double t) override;

  void PrintFirstDerivative(double t) override;

  [[nodiscard]] int GetType() const override;

  [[nodiscard]] double GetRadius() const override;

 private:
  Point center_;
  double small_radius_ = 0;
  double big_radius_ = 0;
};

class Circle : public Figure {
 public:
  Circle() = default;
  Circle(Point p, double r) : center_(std::move(p)), radius_(r){};

  bool Fill(double x, double y, double z, double r, double small_r) override;

  Point GetPoint(double t) override;

  Point GetFirstDerivative(double t) override;

  void PrintPoint(double t) override;

  void PrintFirstDerivative(double t) override;

  [[nodiscard]] int GetType() const override;

  [[nodiscard]] double GetRadius() const override;

 private:
  Point center_;
  double radius_ = 0;
};

class Helix : public Figure {
 public:
  Helix() = default;
  Helix(Point p, double r, double s)
      : center_(std::move(p)), radius_(r), step_(s){};

  bool Fill(double x, double y, double z, double r, double s) override;

  Point GetPoint(double t) override;

  Point GetFirstDerivative(double t) override;

  void PrintPoint(double t) override;

  void PrintFirstDerivative(double t) override;

  [[nodiscard]] int GetType() const override;

  [[nodiscard]] double GetRadius() const override;

 private:
  Point center_;
  double radius_ = 0;
  double step_ = 0;
};

}  // namespace curves

#endif  // SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H
