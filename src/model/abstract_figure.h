#ifndef SUPPORT_OF_3D_CURVES_HIERARCHY_ABSTRACT_FIGURE_H
#define SUPPORT_OF_3D_CURVES_HIERARCHY_ABSTRACT_FIGURE_H

#include <memory>

#include "figures.h"
#include "point.h"

namespace curves {

enum Types { kEllipse = 0, kCircle, kHelix, kUnknown };

class Figure {
 public:
  virtual ~Figure() = default;

  virtual bool Fill(double x, double y, double z, double r, double arg) = 0;

  virtual Point GetPoint(double t) = 0;

  virtual Point GetFirstDerivative(double t) = 0;

  virtual void PrintPoint(double t) = 0;

  virtual void PrintFirstDerivative(double t) = 0;

  [[nodiscard]] virtual int GetType() const = 0;

  [[nodiscard]] virtual double GetRadius() const = 0;
};

}  // namespace curves

#endif  // SUPPORT_OF_3D_CURVES_HIERARCHY_ABSTRACT_FIGURE_H
