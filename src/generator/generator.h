#ifndef SUPPORT_OF_3D_CURVES_HIERARCHY_GENERATOR_H
#define SUPPORT_OF_3D_CURVES_HIERARCHY_GENERATOR_H

#include <list>

#include "../model/figures.h"

namespace curves {

class Generator {
 public:
  Generator() = default;

  std::list<std::shared_ptr<Figure>> Generate();

 private:
  std::list<std::shared_ptr<Figure>> fig_{};
  std::shared_ptr<Figure> figure_;

  void CreateFigure(int type);

  void GenerateCircles(int count);
  void GenerateEllipse(int count);
  void GenerateHelix(int count);
};

}  // namespace curves

#endif  // SUPPORT_OF_3D_CURVES_HIERARCHY_GENERATOR_H
